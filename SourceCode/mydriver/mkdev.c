/***********************************************************************************
 ***时间：2016.09.14
 *功能描述：自动在/dev目录下创建设备节点的示例代码,设备号采用的是静态设备号
 *作者：Sun Jack
 *版本：1.0
 ***********************************************************************************/

#include <linux/module.h>  
#include <linux/module.h>  
#include <linux/kernel.h>  
#include <linux/init.h>  
#include <linux/fs.h>  
#include <linux/cdev.h>  
#include <linux/device.h>  
#include <asm/uaccess.h>   
  
#define HELLO_MAJOR 250  
#define HELLO_MINOR 0  
#define NUMBER_OF_DEVICES 2  
  
struct class *hello_class;  
static struct cdev cdev;  
dev_t devno;  
  
static ssize_t hello_read(struct file *file, char __user *buf, size_t count,  
                loff_t *ppos)  
{  
    char *str = "hello world";  
  
    copy_to_user(buf,str,strlen(str));  
    *(buf + strlen(str)) = '\n';  
    return count;  
}  
  
static ssize_t hello_open(struct inode *inode,struct file *file)  
{  
    return 0;   
}  
  
static const struct file_operations hello_fops = {  
        .open = hello_open,  
        .read = hello_read,  
        .owner = THIS_MODULE,  
};  
  
static int __init hello_init(void)  
{  
    int ret;  
    //主设备号和次设备号
    devno = MKDEV(HELLO_MAJOR,HELLO_MINOR);  
  
    if(HELLO_MAJOR){  
        ret = register_chrdev_region(devno,NUMBER_OF_DEVICES,"chrdev");  
    }else{  
        ret = alloc_chrdev_region(&devno, 0, NUMBER_OF_DEVICES, "chrdev");  
    }  
    if(ret < 0){  
        printk("%s register chrdev error\n",__func__);  
        return ret;  
    }  
    //在/sys目录下创建一个类，名为hello_char_calss
    hello_class = class_create(THIS_MODULE,"hello_char_calss");  
    if(IS_ERR(hello_class)){  
        printk("%s create class error\n",__func__);  
        return -1;  
    }  
    //函数功能在/dev目录下自动创建名为chrdev的设备节点
    device_create(hello_class, NULL, devno, NULL, "chrdev");  
      
    //cdev结构体和file_operations结构体关联的函数  
    cdev_init(&cdev, &hello_fops);  
    cdev.owner = THIS_MODULE;  
    cdev_add(&cdev, devno, NUMBER_OF_DEVICES);  
  
    return 0;  
}  
  
  
static void __exit hello_exit(void)  
{  
    printk("%s",__func__);  
    cdev_del(&cdev);  
    device_destroy(hello_class,devno);  
    class_destroy(hello_class);  
    unregister_chrdev_region(devno,NUMBER_OF_DEVICES);  
  
}  
  
module_init(hello_init);  
module_exit(hello_exit);  
MODULE_LICENSE("GPL");  
MODULE_AUTHOR("Sun Jack"); 
