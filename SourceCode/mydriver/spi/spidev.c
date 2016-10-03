/*****************************************************************************
 *                            spidev.c
 * 功能描述：
 *		Simple synchronous(同步的，同时的) userspace interface to SPI devices
 * 		简单的同步用户空间接口SPI设备     
 * 
 *	Linux系统提供的SPI用户接口函数的文件；部分的代码使用英文注释，方便自己
 *  以后进一步的研究
 *  注释作者：Sun Jack
 *  注释日期：2016.09.20 
 *  
 ******************************************************************************/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/ioctl.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/list.h>
#include <linux/errno.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/compat.h>

#include <linux/spi/spi.h>
#include <linux/spi/spidev.h>

#include <asm/uaccess.h>


/*
 * This supports access to SPI devices using normal userspace I/O calls.
 * Note that while traditional UNIX/POSIX I/O semantics are half duplex,
 * and often mask message boundaries, full SPI support requires full duplex
 * transfers.  There are several kinds of internal message boundaries to
 * handle chipselect management and other protocol options.
 *
 * SPI has a character major number assigned.  We allocate minor numbers
 * dynamically using a bitmask.  You must use hotplug tools, such as udev
 * (or mdev with busybox) to create and destroy the /dev/spidevB.C device
 * nodes, since there is no fixed association of minor numbers with any
 * particular SPI bus or device.
 */
#define SPIDEV_MAJOR			153	/* assigned */           //spidev主设备号
#define N_SPI_MINORS			32	/* ... up to 256 */

static DECLARE_BITMAP(minors, N_SPI_MINORS);     //声明次设备位图


/* Bit masks for spi_device.mode management.  Note that incorrect
 * settings for some settings can cause *lots* of trouble for other
 * devices on a shared bus:
 *
 *  - CS_HIGH ... this device will be active when it shouldn't be
 *  - 3WIRE ... when active, it won't behave as it should
 *  - NO_CS ... there will be no explicit message boundaries; this
 *	is completely incompatible with the shared bus model
 *  - READY ... transfers may proceed when they shouldn't.
 *
 * REVISIT should changing those flags be privileged?
 */
#define SPI_MODE_MASK		(SPI_CPHA | SPI_CPOL | SPI_CS_HIGH \
				| SPI_LSB_FIRST | SPI_3WIRE | SPI_LOOP \
				| SPI_NO_CS | SPI_READY)

struct spidev_data {
	dev_t			devt;			//设备号
	spinlock_t		spi_lock;		//自旋锁
	struct spi_device	*spi;		//指向spi设备结构
	struct list_head	device_entry;	//spi设备链表device_list挂接点

	/* buffer is NULL unless this device is open (users > 0) */
	struct mutex		buf_lock;		//互斥锁
	unsigned		users;				//使用者计数
	u8			*buffer;				//缓冲区
};

static LIST_HEAD(device_list);		//声明spi设备链表	
static DEFINE_MUTEX(device_list_lock);//定义互斥锁

static unsigned bufsiz = 4096;	//最大传输缓冲区大小
module_param(bufsiz, uint, S_IRUGO);//模块参数
MODULE_PARM_DESC(bufsiz, "data bytes in biggest supported SPI message");

/*-------------------------------------------------------------------------*/

/*
 * We can't use the standard synchronous wrappers for file I/O; we
 * need to protect against async removal of the underlying spi_device.
 */
static void spidev_complete(void *arg)
{
	complete(arg);//调用complete
}
//继续spidev_sync函数
static ssize_t
spidev_sync(struct spidev_data *spidev, struct spi_message *message)
{
	DECLARE_COMPLETION_ONSTACK(done);
	int status;

	message->complete = spidev_complete;//设置spi消息的complete方法 回调函数
	//设置个完成量
	message->context = &done;

	spin_lock_irq(&spidev->spi_lock);
	if (spidev->spi == NULL)//判断是否有指定对应的spi设备
		status = -ESHUTDOWN;
	else
		//继续调用spi_async函数
		status = spi_async(spidev->spi, message);//spi异步同步
	spin_unlock_irq(&spidev->spi_lock);

	if (status == 0) {
		//等待完成
		wait_for_completion(&done);	//等待传输完成
		status = message->status;	//获取spi消息传输事务状态
		if (status == 0)
			status = message->actual_length;//status等于传输的实际长度
	}
	return status;		//返回实际传输长度
}

static inline ssize_t
spidev_sync_write(struct spidev_data *spidev, size_t len)
{
	struct spi_transfer	t = {
			.tx_buf		= spidev->buffer,	//发送缓冲区
			.len		= len,				//发送数据长度
		};
	struct spi_message	m;

	spi_message_init(&m);					//初始化spi消息(初始化spi传递事务队列)
	spi_message_add_tail(&t, &m);			//添加spr传递到该队列
	return spidev_sync(spidev, &m);			//同步读写
}
//跟进spidev_sync_read函数，下面的操作比较直白，简要分析下
//只关注主流程
static inline ssize_t
spidev_sync_read(struct spidev_data *spidev, size_t len)
{
	//临时传输操作结构
	struct spi_transfer	t = {
			.rx_buf		= spidev->buffer,	//接收缓冲区
			.len		= len,				//接收数据长度
		};

	//传输所用的信息结构
	struct spi_message	m;
	//初始化该结构
	spi_message_init(&m);					//初始化spi消息(初始化spi传递事务队列)
	//添加到请求队列尾
	spi_message_add_tail(&t, &m);			//添加spr传递到该队列
	//调用spidev_sync继续
	return spidev_sync(spidev, &m);			//同步读写
}

/*-------------------------------------------------------------------------*/

/* Read-only message with current device setup */
static ssize_t
spidev_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	struct spidev_data	*spidev;
	ssize_t			status = 0;

	/* chipselect only toggles at start or end of operation */
	if (count > bufsiz)				//传输数据大于缓冲区容量
		return -EMSGSIZE;
//得到传递的结构
	spidev = filp->private_data;	//从文件私有数据指针获取spidev_data
	
	printk("spi use read!\n");

	mutex_lock(&spidev->buf_lock);	//上互斥锁
	//调用具体的函数
	status = spidev_sync_read(spidev, count);	//同步读,返回传输数据长度
	if (status > 0) {
		unsigned long	missing;				//丢失的数据个数
		//将得到的信息传递给用户
		missing = copy_to_user(buf, spidev->buffer, status);	//内核空间复制到用户空间
		if (missing == status)		//丢失的数据个数等于要传输的数据个数
			status = -EFAULT;
		else
			status = status - missing;			//传输成功的数据个数
	}
	mutex_unlock(&spidev->buf_lock);			//解互斥锁

	return status;								//返回读取成功的数据个数
}

/* Write-only message with current device setup */
static ssize_t
spidev_write(struct file *filp, const char __user *buf,
		size_t count, loff_t *f_pos)
{
	struct spidev_data	*spidev;
	ssize_t			status = 0;
	unsigned long		missing;

	/* chipselect only toggles at start or end of operation */
	if (count > bufsiz)				//传输数据大于缓冲区容量
		return -EMSGSIZE;

	spidev = filp->private_data;	//从文件私有数据指针获取spidev_data

	mutex_lock(&spidev->buf_lock);	//上互斥锁
	missing = copy_from_user(spidev->buffer, buf, count);	//用户空间复制到内核空间
	if (missing == 0) {									//传输失败个数为0
		status = spidev_sync_write(spidev, count);		//同步写,返回传输数据长度
	} else
		status = -EFAULT;
	mutex_unlock(&spidev->buf_lock);			//解互斥锁
	printk("the write is used!\n");
	return status;						//返回写数据的实际个数
}

static int spidev_message(struct spidev_data *spidev,
		struct spi_ioc_transfer *u_xfers, unsigned n_xfers)
{
	struct spi_message	msg;
	struct spi_transfer	*k_xfers;
	struct spi_transfer	*k_tmp;
	struct spi_ioc_transfer *u_tmp;
	unsigned		n, total;
	u8			*buf;
	int			status = -EFAULT;

	spi_message_init(&msg);				//初始化spi消息(初始化spi传递事务队列)
	k_xfers = kcalloc(n_xfers, sizeof(*k_tmp), GFP_KERNEL);		//分配spi传输指针内存
	if (k_xfers == NULL)
		return -ENOMEM;

	/* Construct spi_message, copying any tx data to bounce buffer.
	 * We walk the array of user-provided transfers, using each one
	 * to initialize a kernel version of the same transfer.
	 */
	buf = spidev->buffer;			//获取spidev_data的缓冲区
	total = 0;
	//n=xfers为spi_ioc_transfer个数,u_tmp = u_xfers为要处理的spi_ioc_transfer指针
	for (n = n_xfers, k_tmp = k_xfers, u_tmp = u_xfers;
			n;
			n--, k_tmp++, u_tmp++) {
		k_tmp->len = u_tmp->len;		//设置传输信息的长度

		total += k_tmp->len;			//累加传输信息的总长度
		if (total > bufsiz) {			//信息量超过bufsiz缓冲区最大容量
			status = -EMSGSIZE;
			goto done;
		}

		if (u_tmp->rx_buf) {		//接收缓冲区指针不为空	
			k_tmp->rx_buf = buf;	//缓冲区指向buf	
			if (!access_ok(VERIFY_WRITE, (u8 __user *)
						(uintptr_t) u_tmp->rx_buf,
						u_tmp->len))
				goto done;
		}
		if (u_tmp->tx_buf) {			//接收缓冲区指针不为空
			k_tmp->tx_buf = buf;		//缓冲区指向buf
			if (copy_from_user(buf, (const u8 __user *)
						(uintptr_t) u_tmp->tx_buf,
					u_tmp->len))
				goto done;
		}
		buf += k_tmp->len;			//缓冲区指针移动一个传输信息的长度

		k_tmp->cs_change = !!u_tmp->cs_change;	//设置cs_change
		k_tmp->bits_per_word = u_tmp->bits_per_word;	//设置bits_per_word 一个字多少位
		k_tmp->delay_usecs = u_tmp->delay_usecs;	//设置delay_usecs 毫秒级延时
		k_tmp->speed_hz = u_tmp->speed_hz;			//设置speed_hz 速率
#ifdef VERBOSE
		dev_dbg(&spidev->spi->dev,
			"  xfer len %zd %s%s%s%dbits %u usec %uHz\n",
			u_tmp->len,
			u_tmp->rx_buf ? "rx " : "",
			u_tmp->tx_buf ? "tx " : "",
			u_tmp->cs_change ? "cs " : "",
			u_tmp->bits_per_word ? : spidev->spi->bits_per_word,
			u_tmp->delay_usecs,
			u_tmp->speed_hz ? : spidev->spi->max_speed_hz);
#endif
		spi_message_add_tail(k_tmp, &msg);		//添加spr传递到该队列
	}
	//for循环的作用是将spi_ioc_transfer批量转换为spi传递结构体spi_transfer,然后添加进spi传递事务队列
	status = spidev_sync(spidev, &msg);		//同步读写
	if (status < 0)
		goto done;

	/* copy any rx data out of bounce buffer */
	buf = spidev->buffer;	//获取spidev_data缓冲区指针
	for (n = n_xfers, u_tmp = u_xfers; n; n--, u_tmp++) {	//批量从内核空间复制spi_ioc_transfer到用户空间
		if (u_tmp->rx_buf) {	//判断是否存在接收缓冲区
			if (__copy_to_user((u8 __user *)
					(uintptr_t) u_tmp->rx_buf, buf,
					u_tmp->len)) {
				status = -EFAULT;
				goto done;
			}
		}
		buf += u_tmp->len;	//buf指针位置调整指向下一个spi_ioc_transfer
	}
	status = total;			//status等于实际传输的数据长度

done:
	kfree(k_xfers);			//释放k_xfers
	return status;			//返回实际传输的数据长度
}

static long
spidev_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	int			err = 0;
	int			retval = 0;
	struct spidev_data	*spidev;
	struct spi_device	*spi;
	u32			tmp;
	unsigned		n_ioc;
	struct spi_ioc_transfer	*ioc;

	/* Check type and command number */
	if (_IOC_TYPE(cmd) != SPI_IOC_MAGIC)	//判断控制命令的类型
		return -ENOTTY;

	/* Check access direction once here; don't repeat below.
	 * IOC_DIR is from the user perspective, while access_ok is
	 * from the kernel perspective; so they look reversed.
	 */
	if (_IOC_DIR(cmd) & _IOC_READ)		//判断控制命令的方向是否为读read
		err = !access_ok(VERIFY_WRITE,
				(void __user *)arg, _IOC_SIZE(cmd));//判断传输数据大小
	if (err == 0 && _IOC_DIR(cmd) & _IOC_WRITE)		//判断控制命令的方向是否为写write
		err = !access_ok(VERIFY_READ,
				(void __user *)arg, _IOC_SIZE(cmd));	//判断传输数据大小	
	if (err)
		return -EFAULT;

	/* guard against device removal before, or while,
	 * we issue this ioctl.
	 */
	spidev = filp->private_data;			//从文件私有数据中获取spidev_data
	spin_lock_irq(&spidev->spi_lock);		//上自旋锁
	spi = spi_dev_get(spidev->spi);			//获取spi设备
	spin_unlock_irq(&spidev->spi_lock);		//解自旋锁

	if (spi == NULL)	//获取spi设备失败
		return -ESHUTDOWN;		//则返回错误

	/* use the buffer lock here for triple duty:
	 *  - prevent I/O (from us) so calling spi_setup() is safe;
	 *  - prevent concurrent SPI_IOC_WR_* from morphing
	 *    data fields while SPI_IOC_RD_* reads them;
	 *  - SPI_IOC_MESSAGE needs the buffer locked "normally".
	 */
	mutex_lock(&spidev->buf_lock);		//上互斥锁

	switch (cmd) {
	/* read requests */
	case SPI_IOC_RD_MODE:		//设置spi读模式
		retval = __put_user(spi->mode & SPI_MODE_MASK,
					(__u8 __user *)arg);
		break;
	case SPI_IOC_RD_LSB_FIRST:	//设置spi读最低有效位
		retval = __put_user((spi->mode & SPI_LSB_FIRST) ?  1 : 0,
					(__u8 __user *)arg);
		break;
	case SPI_IOC_RD_BITS_PER_WORD:	//设置spi读每个字含多个个位
		retval = __put_user(spi->bits_per_word, (__u8 __user *)arg);
		break;
	case SPI_IOC_RD_MAX_SPEED_HZ:	//设置spi读最大速率
		retval = __put_user(spi->max_speed_hz, (__u32 __user *)arg);
		break;

	/* write requests */
	case SPI_IOC_WR_MODE:	//设置spi写模式
		retval = __get_user(tmp, (u8 __user *)arg);
		if (retval == 0) {
			u8	save = spi->mode;	//获取spi设备模式

			if (tmp & ~SPI_MODE_MASK) {
				retval = -EINVAL;
				break;
			}

			tmp |= spi->mode & ~SPI_MODE_MASK;
			spi->mode = (u8)tmp;
			retval = spi_setup(spi);	//配置spi设备
			if (retval < 0)
				spi->mode = save;
			else
				dev_dbg(&spi->dev, "spi mode %02x\n", tmp);
		}
		break;
	case SPI_IOC_WR_LSB_FIRST:	//设置spi写最低有效位
		retval = __get_user(tmp, (__u8 __user *)arg);
		if (retval == 0) {
			u8	save = spi->mode;	//获取spi设备模式

			if (tmp)
				spi->mode |= SPI_LSB_FIRST;
			else
				spi->mode &= ~SPI_LSB_FIRST;
			retval = spi_setup(spi);	//配置spi设备
			if (retval < 0)
				spi->mode = save;
			else
				dev_dbg(&spi->dev, "%csb first\n",
						tmp ? 'l' : 'm');
		}
		break;
	case SPI_IOC_WR_BITS_PER_WORD:	//设置spi写每个字含多少个位
		retval = __get_user(tmp, (__u8 __user *)arg);	//用户空间获取数据
		if (retval == 0) {
			u8	save = spi->bits_per_word;	//获取spi设备 每个字含多少位

			spi->bits_per_word = tmp;	//更新新的spi设备  每个字含多少位
			retval = spi_setup(spi);	//配置spi设备
			if (retval < 0)		//配置失败
				spi->bits_per_word = save;	//还原spi设备 每个字含多少位
			else
				dev_dbg(&spi->dev, "%d bits per word\n", tmp);
		}
		break;
	case SPI_IOC_WR_MAX_SPEED_HZ:	//设置spi写最大速率
		retval = __get_user(tmp, (__u32 __user *)arg);	//用户空间获取数据
		if (retval == 0) {
			u32	save = spi->max_speed_hz;	//获取spi设备最大速率

			spi->max_speed_hz = tmp;	//更新新的spi设备最大速率
			retval = spi_setup(spi);	//配置spi设备
			if (retval < 0)		配置失败
				spi->max_speed_hz = save; 	//还原spi设备最大速率
			else
				dev_dbg(&spi->dev, "%d Hz (max)\n", tmp);
		}
		break;

	default:
		/* segmented and/or full-duplex I/O request */
		//命令必须为写方向的命令，且传输数据必须是SPI_IOC_MESSAGE()修饰的命令
		if (_IOC_NR(cmd) != _IOC_NR(SPI_IOC_MESSAGE(0))
				|| _IOC_DIR(cmd) != _IOC_WRITE) {
			retval = -ENOTTY;
			break;
		}

		tmp = _IOC_SIZE(cmd);	//计算传输数据大小
		if ((tmp % sizeof(struct spi_ioc_transfer)) != 0) {		//判断是否为spi_ioc_transfer对齐
			retval = -EINVAL;
			break;
		}
		n_ioc = tmp / sizeof(struct spi_ioc_transfer);	//计算出spi_ioc_transfer数据的个数
		if (n_ioc == 0)
			break;

		/* copy into scratch area */
		ioc = kmalloc(tmp, GFP_KERNEL);	//分配spi_ioc_transfer指针ioc内存
		if (!ioc) {
			retval = -ENOMEM;
			break;
		}
		if (__copy_from_user(ioc, (void __user *)arg, tmp)) {	//从用户空间复制到内核空间
			kfree(ioc);	//复制失败则释放ioc内存
			retval = -EFAULT;
			break;
		}

		/* translate to spi_message, execute */
		retval = spidev_message(spidev, ioc, n_ioc);	//spidev消息处理
		kfree(ioc);		//释放ioc内存
		break;
	}

	mutex_unlock(&spidev->buf_lock);	//解互斥锁
	spi_dev_put(spi);			//增加spi设备的引用计数
	return retval;
}

#ifdef CONFIG_COMPAT
static long
spidev_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	return spidev_ioctl(filp, cmd, (unsigned long)compat_ptr(arg));
}
#else
#define spidev_compat_ioctl NULL
#endif /* CONFIG_COMPAT */
//按应用的操作顺序先看下open函数
static int spidev_open(struct inode *inode, struct file *filp)
{
	struct spidev_data	*spidev;
	int			status = -ENXIO;

	mutex_lock(&device_list_lock);		//上互斥锁

//遍历spi设备链表device_list，根据设备号找到spidev_data结构
	list_for_each_entry(spidev, &device_list, device_entry) {	//遍历device_list
		if (spidev->devt == inode->i_rdev) {	//判断设备号找到对应的设备
			status = 0;	//设置状态为0
			break;
		}
	}
	if (status == 0) {	//找得到对应的设备
		//buffer为空，为其申请内存
		if (!spidev->buffer) {	//spidev_data缓冲区为空
			spidev->buffer = kmalloc(bufsiz, GFP_KERNEL);	//则分配内存
			if (!spidev->buffer) {	//还空
				dev_dbg(&spidev->spi->dev, "open/ENOMEM\n");	//调试了
				status = -ENOMEM;
			}
		}
		//设备用户使用量+1
		if (status == 0) {		//找得到对应的设备
			spidev->users++;	//spidev_data使用者计数++

			//传到filp的私有成员，在read，write的时候可以从其得到该结构
			filp->private_data = spidev;	//spidev_data放在文件的私有数据里
			nonseekable_open(inode, filp);	//设置文件的打开模式(文件读写指针不会跟随读写操作移动)
		}
	} else
		pr_debug("spidev: nothing for minor %d\n", iminor(inode));

	mutex_unlock(&device_list_lock);	//解互斥锁
	return status;
}

static int spidev_release(struct inode *inode, struct file *filp)
{
	struct spidev_data	*spidev;
	int			status = 0;

	mutex_lock(&device_list_lock);
	spidev = filp->private_data;	//获取spidev_data 
	filp->private_data = NULL;		//清除文件的私有数据指针

	/* last close? */
	spidev->users--;		//使用者个数--
	if (!spidev->users) {	//如果使用者个数为0
		int		dofree;

		kfree(spidev->buffer);	//释放spidev_data的缓冲区内存
		spidev->buffer = NULL;	//清除spidev_data缓冲区指针

		/* ... after we unbound from the underlying device? */
		spin_lock_irq(&spidev->spi_lock);	//上自旋锁
		dofree = (spidev->spi == NULL);//判断spi设备是否与spidev_data解绑了
		spin_unlock_irq(&spidev->spi_lock);  //解自旋锁

		if (dofree)		//没有捆绑的spi设备
			kfree(spidev);	//则释放spidev_data内存
	}
	mutex_unlock(&device_list_lock);

	return status;
}
//设备的读写函数的系统接口连接
static const struct file_operations spidev_fops = {  //文件操作函数集
	.owner =	THIS_MODULE,
	/* REVISIT switch to aio primitives, so that userspace
	 * gets more complete API coverage.  It'll simplify things
	 * too, except for the locking.
	 */
	.write =	spidev_write,	//写write
	.read =		spidev_read,	//读read
	.unlocked_ioctl = spidev_ioctl,//控制ioctl
	.compat_ioctl = spidev_compat_ioctl,
	.open =		spidev_open,	//打开open
	.release =	spidev_release,	//释放release
	.llseek =	no_llseek,		//文件指针移动 no_llseek表示没有移动
};

/*-------------------------------------------------------------------------*/

/* The main reason to have this class is to make mdev/udev create the
 * /dev/spidevB.C character device nodes exposing our userspace API.
 * It also simplifies memory management.
 */

static struct class *spidev_class;

/*-------------------------------------------------------------------------*/

static int __devinit spidev_probe(struct spi_device *spi)
{
	struct spidev_data	*spidev;
	int			status;
	unsigned long		minor;

	/* Allocate driver data */
	spidev = kzalloc(sizeof(*spidev), GFP_KERNEL); 	//分配spidev_data内存
	if (!spidev)
		return -ENOMEM;

	/* Initialize the driver data */
	spidev->spi = spi;		//设置spidev_data->spi(spi设备)
	spin_lock_init(&spidev->spi_lock);	
	mutex_init(&spidev->buf_lock);

	INIT_LIST_HEAD(&spidev->device_entry);	//初始化spidev_data入口链表

	/* If we can allocate a minor number, hook up this device.
	 * Reusing minors is fine so long as udev or mdev is working.
	 */
	mutex_lock(&device_list_lock);
	minor = find_first_zero_bit(minors, N_SPI_MINORS);	//查找次设备位图分配次设备号
	if (minor < N_SPI_MINORS) {
		struct device *dev;

		spidev->devt = MKDEV(SPIDEV_MAJOR, minor);	//计算出设备号
		//创建设备/dev/spidev%d.%d(spidev总线号.片选号)
		dev = device_create(spidev_class, &spi->dev, spidev->devt,
				    spidev, "spidev%d.%d",
				    spi->master->bus_num, spi->chip_select);
		status = IS_ERR(dev) ? PTR_ERR(dev) : 0;
	} else {
		dev_dbg(&spi->dev, "no minor number available!\n");
		status = -ENODEV;
	}
	if (status == 0) {		//分配设备号成功
		set_bit(minor, minors);		//更新次设备位图
		list_add(&spidev->device_entry, &device_list);	//添加进设备链表
	}
	mutex_unlock(&device_list_lock);

	if (status == 0)
		spi_set_drvdata(spi, spidev);	//spi->dev->p->driver_data=spidev
	else
		kfree(spidev);

	return status;
}

static int __devexit spidev_remove(struct spi_device *spi)
{
	struct spidev_data	*spidev = spi_get_drvdata(spi);//根据spi设备获取spidev_data

	/* make sure ops on existing fds can abort cleanly */
	spin_lock_irq(&spidev->spi_lock);//上自旋锁
	spidev->spi = NULL;		//清空spidev_data->spi指针
	spi_set_drvdata(spi, NULL);		//spi->dev->p->driver_data=NULL
	spin_unlock_irq(&spidev->spi_lock);  //解自旋锁

	/* prevent new opens */
	mutex_lock(&device_list_lock);		//上互斥锁
	list_del(&spidev->device_entry);	//删除spidev_data入口链表
	device_destroy(spidev_class, spidev->devt);  //销毁/dev/spidev%d.%d
	clear_bit(MINOR(spidev->devt), minors);		//清除次设备位图对应位	
	if (spidev->users == 0)		//使用者个数为0
		kfree(spidev);		//释放spidev_data内存
	mutex_unlock(&device_list_lock);	//解互斥锁

	return 0;
}

static struct spi_driver spidev_spi_driver = {		//spi设备驱动
	.driver = {
		.name =		"spidev",
		.owner =	THIS_MODULE,
	},
	.probe =	spidev_probe,	//spidev的probe方法(当注册了modalias域为"spidev"的spi设备或板级设备,则会调用probe方法)
	.remove =	__devexit_p(spidev_remove),  //spidev的remove方法

	/* NOTE:  suspend/resume methods are not necessary here.
	 * We don't do anything except pass the requests to/from
	 * the underlying controller.  The refrigerator handles
	 * most issues; the controller driver handles the rest.
	 */
};

/*-------------------------------------------------------------------------*/

static int __init spidev_init(void)  //spidev接口初始化
{
	int status;

	/* Claim our 256 reserved device numbers.  Then register a class
	 * that will key udev/mdev to add/remove /dev nodes.  Last, register
	 * the driver which manages those device numbers.
	 */
	BUILD_BUG_ON(N_SPI_MINORS > 256);
	//register_chrdev函数,注册主设备号，设备名，关联read，write函数
	//注册字符设备,主设备号SPIDEV_MAJOR=153,捆绑的设备操作函数集为spidev_fops
	status = register_chrdev(SPIDEV_MAJOR, "spi", &spidev_fops);
	if (status < 0)
		return status;
	//创建一个名称为spidev的class
	spidev_class = class_create(THIS_MODULE, "spidev");	//创建设备类spidev_class
	if (IS_ERR(spidev_class)) {
		unregister_chrdev(SPIDEV_MAJOR, spidev_spi_driver.driver.name);
		return PTR_ERR(spidev_class);
	}
	//注册spi_driver，默认的总线是spi_bus_type，函数原型定义在spi.c文件
	status = spi_register_driver(&spidev_spi_driver);//注册spi设备驱动spidev_spi_driver
	if (status < 0) {
		class_destroy(spidev_class);
		unregister_chrdev(SPIDEV_MAJOR, spidev_spi_driver.driver.name);
	}
	return status;
}
module_init(spidev_init);	//声明初始化入口

static void __exit spidev_exit(void)	//spidev接口销毁
{
	spi_unregister_driver(&spidev_spi_driver);	//注销spi设备驱动spidev_spi_driver
	class_destroy(spidev_class);	//注销设备类spidev_class
	unregister_chrdev(SPIDEV_MAJOR, spidev_spi_driver.driver.name); //注销字符设备
}
module_exit(spidev_exit);   //声明初始化出口

MODULE_AUTHOR("Andrea Paterniani, <a.paterniani@swapp-eng.it>");
MODULE_DESCRIPTION("User mode SPI device interface");
MODULE_LICENSE("GPL");
MODULE_ALIAS("spi:spidev");

/*
 *	整理下ioctl的命令：
 *
 *	SPI_IOC_RD_MODE		//读 模式
 *	SPI_IOC_RD_LSB_FIRST	//读 LSB
 *	SPI_IOC_RD_BITS_PER_WORD	//读 每字多少位
 *	SPI_IOC_RD_MAX_SPEED_HZ	//读 最大速率
 *	SPI_IOC_WR_MODE		//写 模式
 *	SPI_IOC_WR_LSB_FIRST	//写 LSB
 *	SPI_IOC_WR_BITS_PER_WORD	//写 每字多少位
 *	SPI_IOC_WR_MAX_SPEED_HZ	//写 最大速率
 *	SPI_IOC_MESSAGE(n)		//传输n个数据包
 *
 */
