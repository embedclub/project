/*****************************************************************
 ********                 platform平台驱动                ********
 * 时间： 2016.09.17  16.30
 * 功能： platform平台驱动定义和注册的示例代码
 * 作者： Sun Jack
 * 验证平台：已经在tina2.0的源码 + R16的开发板上使用成功
 * 编译方式：采用在内核里面直接添加代码，并编译成模块测试
 * 存在问题：不能自动创建设备节点  /dev/目录下没有设备节点
 ***                                                           ***
 *****************************************************************/

#include <linux/device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/platform_device.h>

MODULE_AUTHOR("Sun Jack");
MODULE_LICENSE("Dual BSD/GPL");

/*平台设备和平台驱动都有添加时，匹配设备和驱动，会调用probe这个函数*/
static int my_probe(struct device *dev)
{
	printk("Driver found device which my driver can handle!\n");
	return 0;
}

/*平台设备被注销后，会调用这个函数 */
static int my_remove(struct device *dev)
{
	printk("Driver found device unpluged!\n");
	return 0;
}
/*platform平台驱动的结构体定义 */
static struct platform_driver my_driver = {
	.probe	= my_probe,
	.remove	= my_remove,
	.driver	= {
		.owner	= THIS_MODULE,
		.name	= "my_dev",//此驱动名字需要与设备名字相同，只有相同才能调用.probe函数
	},
};

/* __init这个标号为了限制my_driver_init函数只能被调用执行一次 */
static int __init my_driver_init(void)
{
	/*注册平台驱动 传入的参数是platform_driver结构体*/
	return platform_driver_register(&my_driver);
}

static int __exit my_driver_exit(void)
{
	platform_driver_unregister(&my_driver);
}

module_init(my_driver_init);
module_exit(my_driver_exit);

