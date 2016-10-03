/*****************************************************************
 ********                 platform平台设备                ********
 * 时间： 2016.09.17  16.30
 * 功能： platform平台设备定义和注册的示例代码
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
#include <linux/platform_device.h>

MODULE_AUTHOR("Sun Jack");
MODULE_LICENSE("Dual BSD/GPL");

static struct platform_device *my_device;

static int __init my_device_init(void)
{
	int ret = 0;
	
	/*分配结构 */
	my_device = platform_device_alloc("my_dev", -1);

	/*注册设备 */
	ret = platform_device_add(my_device);

	/*注册失败，释放相关内存 */
	if (ret)
		platform_device_put(my_device);

	return ret;		
}

static void my_device_exit(void)
{
	platform_device_unregister(my_device);
}

module_init(my_device_init);
module_exit(my_device_exit);
