/*****************************************************************
 ********                      Kset                       ********
 * 创建时间： 2016.09.17  19.30
 * 修改时间： 2016.09.18  10.15
 * 功能： Kset使用的示例代码，Kset是Kobject的集合
	  Kset用于保存子目录
 * 作者： Sun Jack
 * 验证平台：已经在tina2.0的源码 + R16的开发板上使用成功
 * 编译方式：采用在内核里面直接添加代码，并编译成模块测试
 * 存在问题：//下面这句多余，是为了规避kernel oops bug
        	kset_p.kobj.ktype = &my_kobj_type;
	     关于这本问题还需要继续追究
 * 版本： V1.1
 ***                                                           ***
 *****************************************************************/

#include <linux/device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/stat.h>
#include <linux/kobject.h>

MODULE_AUTHOR("Sun Jack");
MODULE_LICENSE("Dual BSD/GPL");

struct kset kset_p;
struct kset kset_c;
//struct kobject 就是当前发生热插拔的目录
int kset_filter(struct kset *kset, struct kobject *kobj)
{
	printk("Filter: kobj %s.\n", kobj->name);
	return 1; //只有返回1  剩下的两个函数才有作用
}

//有信息传递给用户空间，就可以把信息写到buf里面
const char *kset_name(struct kset *kset, struct kobject *kobj)
{
	static char buf[20];
	printk("Name: kobj %s.\n", kobj->name);
	//返回这个字符串给用户空间的热插拔处理程序
	sprintf(buf, "%s", "kset_name");
	return buf;
}

int kset_uevent(struct kset *kset, struct kobject *kobj, struct kobj_uevent_env *env)
{
	int i = 0;
	printk("uevent: kobj %s.\n", kobj->name);
	//将所有的环境变量打印出来
	while (i < env->envp_idx) {
		printk("%s.\n", env->envp[i]);
		i++;
	}
}

struct kset_uevent_ops uevent_ops = {
    .filter = kset_filter,  //决定是否把事件传递给用户空间  
    .name   = kset_name,    //将字符串返回给用户空间  
    .uevent = kset_uevent,  //添加环境变量  
};

struct kobj_type my_kobj_type;

static int __init kset_test_init(void)
{
	int ret = 0;
	printk("kset test init.\n");
	//kset_p表示父目录
	kobject_set_name(&kset_p.kobj, "kset_p");
	printk("kobject set name ok!\n");
	//下面这句多余，是为了规避kernel oops bug
//	kset_p.kobj.ktype = &my_kobj_type;
	kset_p.uevent_ops = &uevent_ops;
	printk("kobject set uevent ok!\n");
	//kset_register函数定义在lib/kobject.c文件中
	ret = kset_register(&kset_p);//注册目录

	if (ret) {
		printk("kset p register!\n");
		
	}

	//父目录下创建子目录，就会引起热插拔事件	
	//kset_c表示子目录
	kobject_set_name(&kset_c.kobj, "kset_c");
	//基类和继承 表示kset_c的父目录是kset_p
	kset_c.kobj.kset = &kset_p;
//	kset_c.kobj.ktype = &my_kobj_type;
	ret = kset_register(&kset_c);
	if (ret) {
		printk("kset c register!\n");
		kset_unregister(&kset_p);

	}


	return 0;
}
//注销的时候，不需要考虑顺序
static int __exit kset_test_exit(void)
{
	printk("kset test exit.\n");
	kset_unregister(&kset_p);
	kset_unregister(&kset_c);
	return 0;
}

//报错提示init.h文件有问题，一般是缺少“}”引起的
module_init(kset_test_init);
module_exit(kset_test_exit);
