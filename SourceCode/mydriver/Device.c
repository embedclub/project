/*****************************************************************
 ********                  BUS下面的设备                  ********
 * 时间： 2016.09.10  16.30
 * 功能： 自定义BUS的设备定义和注册的示例代码
 * 作者： Sun Jack
 * 验证平台：已经在tina2.0的源码 + R16的开发板上使用成功
 * 编译方式：采用在内核里面直接添加代码，并编译成模块测试
 * 存在问题：不能自动创建设备节点
 ***                                                           ***
 *****************************************************************/

#include <linux/device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>

MODULE_AUTHOR("Scc Jack");
MODULE_LICENSE("Dual BSD/GPL");

extern struct device my_bus;
extern struct bus_type my_bus_type;

/* Why need this ?*/
static void my_dev_release(struct device *dev)
{

}

struct device my_dev = {
	.bus = &my_bus_type,
	.parent = &my_bus,
	.release = my_dev_release,
};

/*
 * Export a simple attribute.
 */
static ssize_t mydev_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%s\n", "This is my device!");
}

static DEVICE_ATTR(dev, S_IRUGO, mydev_show, NULL);

static int __init my_device_init(void)
{
	int ret = 0;
 	
	/* 初始化设备 */	
//	strncpy(my_dev.init_name, "my_dev", BUS_ID_SIZE);
	dev_set_name(&my_dev, "my_dev");

	/*注册设备*/
	device_register(&my_dev);

	/*创建属性文件*/
	device_create_file(&my_dev, &dev_attr_dev);

	return ret;
}

static void my_device_exit(void)
{
	device_unregister(&my_dev);
}

module_init(my_device_init);
module_exit(my_device_exit);

