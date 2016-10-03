/*****************************************************************
 ********              Hello World驱动code                ********
 * 时间： 2016.09.09  16.30
 * 功能： 驱动加载和卸载的示例代码，可以在加载时传入参数
 * 作者： Sun Jack
 * 验证平台：已经在tina2.0的源码 + R16的开发板上使用成功
 * 编译方式：采用在内核里面直接添加代码，并编译成模块测试
 * 存在问题：简单
 * 版本： V1.0
 ***                                                           ***
 *****************************************************************/
//驱动的头文件
#include <linux/init.h>
#include <linux/module.h>
//驱动的证书，遵循的开源协议
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Sun Jack");//驱动的作者

static char *whom = "world";
static int howmany = 1;


static int __init hello_init(void)
{
        printk(KERN_ALERT "Hello world\n");
        int i;
        for(i=0;i<howmany;i++)
        {
                printk(KERN_ALERT "Hello %s\n",whom);
        }
        return 0;
}
static void __exit hello_exit(void)
{
        printk(KERN_ALERT " Hello world exit\n");
}

//代码加载运行或卸载的标志
module_init(hello_init);
module_exit(hello_exit);

//驱动的参数
module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);

//导出参数，可以被别的模块调用，类似于C语言里的extern关键字
EXPORT_SYMBOL(howmany);
EXPORT_SYMBOL(whom);

