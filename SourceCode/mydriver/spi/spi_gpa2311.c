/*
 * this module is about the GPA2311
 * created by Sun Jack 
 * Date 2016.09.13
 * Version 1.0
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/spi/spi.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>

#define DEVICE_NAME     "gpa2311_spi" 
 
static int Gpa2311_spi_open(struct inode *inode,struct file *filp)  
{  
	printk("Gpa2311_spi_open   \n");
	return 0;  
}  
  

static int Gpa2311_spi_release(struct inode *inode,struct file *filp)  
{  
	printk("Gpa2311_spi_release   \n");
	return 0;  
}  
   
static ssize_t Gpa2311_spi_read(struct file *filp,char __user *buf,size_t count,loff_t *f_ops)  
{  
	printk("Gpa2311 spi read!     \n");
	return 0;  
}  

   

static ssize_t Gpa2311_spi_write(struct file *filp,const char __user *buf,size_t count,loff_t *f_ops)  
{  
	printk("gpa2311 spi write \n");
	return 0;
}  

static ssize_t Gpa2311_spi_ioctl(struct inode *inode,struct file *filp,unsigned int cmd,unsigned long data)  
{  
	return 0;  
}  

/*static const struct file_operations spi_fops = {  
	.owner = THIS_MODULE,  
	.open = Gpa2311_spi_open,  
	.read = Gpa2311_spi_read,  
	.write = Gpa2311_spi_write,  
	.ioctl = Gpa2311_spi_ioctl,  
	.release = Gpa2311_spi_release, 
};*/

static int my_probe(struct spi_device *spi)
{
        printk("Driver found device which my driver can handle!\n");
        return 0;
}

static int my_remove(struct spi_device *spi)
{
        printk("Driver found device unpluged!\n");
        return 0;
}


static struct spi_driver Gpa2311_driver = {
        .driver = {
                .name   = "Gpa2311",
                .owner  = THIS_MODULE,
        },
        .probe          = my_probe,
        .remove         = my_remove,
};


static int __init spi_init(void)
{
     	return spi_register_driver(&Gpa2311_driver);
}
 
 
static void __exit spi_exit(void)
{
	spi_unregister_driver(&Gpa2311_driver);
}
 
module_init(spi_init);
module_exit(spi_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sun Jack");
MODULE_DESCRIPTION("SPI Gpa2311 module");
