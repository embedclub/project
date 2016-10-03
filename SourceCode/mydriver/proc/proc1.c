/*****************************************************************
 ********               proc文件系统                      ********
 * 时间： 2016.10.03  16.30
 * 功能： proc文件系统读写学习
 * 作者： Sun Jack
 * 验证平台：已经在tina2.0的源码 + R16的开发板上使用成功
 * 编译方式：采用在内核里面直接添加代码，并编译成模块测试
 * 存在问题：
 ***                                                           ***
 *****************************************************************/

#include <linux/module.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

static struct proc_dir_entry *mydir;
static struct proc_dir_entry *pfile;

static char msg[255];

static int myproc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
        int len = strlen(msg);

        if (off >= len)
                return 0;

        if (count > len - off)
                count = len - off;

        memcpy(page + off, msg + off, count);
        return off + count;
}

static int myproc_write(struct file *file, const char __user *buffer, unsigned long count, void *data)
{
        unsigned long count2 = count;

        if (count2 >= sizeof(msg))
                count2 = sizeof(msg) - 1;

        if (copy_from_user(msg, buffer, count2))
                return -EFAULT;

        msg[count2] = '\0';
        return count;
}

static int __init myproc_init(void)
{
	//创建目录目录存在于/proc下面
        mydir = proc_mkdir("mydir", NULL);
        if (!mydir) {
                printk(KERN_ERR "Can't create /proc/mydir\n");
                return -1;
        }

        pfile = create_proc_entry("pool", 0666, mydir);
        if (!pfile) {
                printk(KERN_ERR "Can't create /proc/mydir/pool\n");
                remove_proc_entry("mydir", NULL);
                return -1;
        }

        pfile->read_proc = myproc_read;
        pfile->write_proc = myproc_write;

        return 0;
}

static void __exit myproc_exit(void)
{
        remove_proc_entry("pool", mydir);
        remove_proc_entry("mydir", NULL);
}

module_init(myproc_init);
module_exit(myproc_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sun Jack");


