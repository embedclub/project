/*****************************************************************
 ********                    Kobject                      ********
 * 时间： 2016.09.17  19.30
 * 功能： Kobject使用的示例代码，Kobject对应在/sys目录下创建一个目录
 * 	  此程序会在运行时，产生目录
 * 作者： Sun Jack
 * 验证平台：已经在tina2.0的源码 + R16的开发板上使用成功
 * 编译方式：采用在内核里面直接添加代码，并编译成模块测试
 * 存在问题：
 * 版本： V1.0
 ***                                                           ***
 *****************************************************************/

#include <linux/device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/stat.h>
 
MODULE_AUTHOR("Sun Jack");
MODULE_LICENSE("Dual BSD/GPL");
 
void obj_test_release(struct kobject *kobject);
ssize_t kobj_test_show(struct kobject *kobject, struct attribute *attr,char *buf);
ssize_t kobj_test_store(struct kobject *kobject,struct attribute *attr,const char *buf, size_t count);
//文件的名字，读写属性 
struct attribute test_attr = {
        .name = "kobj_config",
        .mode = S_IRWXUGO,
};
//属性，多个文件 指针数组 
static struct attribute *def_attrs[] = {
        &test_attr,
        NULL,
};
 
// 
struct sysfs_ops obj_test_sysops =
{
        .show = kobj_test_show,
        .store = kobj_test_store,
};
// 
struct kobj_type ktype = 
{
        .release = obj_test_release,
        .sysfs_ops=&obj_test_sysops,
        .default_attrs=def_attrs,
};
 
void obj_test_release(struct kobject *kobject)
{
        printk("eric_test: release .\n");
}
//读文件的时候调用，下面的函数 
ssize_t kobj_test_show(struct kobject *kobject, struct attribute *attr,char *buf)
{
        printk("have show.\n");
        printk("attrname:%s.\n", attr->name);
        sprintf(buf,"%s\n",attr->name);
        return strlen(attr->name)+2;
}
//写文件的时候,调用的函数 
ssize_t kobj_test_store(struct kobject *kobject,struct attribute *attr,const char *buf, size_t count)
{
        printk("havestore\n");
        printk("write: %s\n",buf);
        return count;
}
//kobject结构体定义，未赋值 
struct kobject kobj;
static int kobj_test_init(void)
{
        printk("kboject test init.\n");
	//初始化kobject，并将其注册到linux系统，kobject创建在/sys目录
	//目录名为：kobject_test,同时在目录里面创建一个文件，名为kobj_config，其
	//定义在struct attribute test_attr结构体中
        kobject_init_and_add(&kobj,&ktype,NULL,"kobject_test");
        return 0;
}
 
static void kobj_test_exit(void)
{
        printk("kobject test exit.\n");
	//目录删除函数
        kobject_del(&kobj);
}
 
module_init(kobj_test_init);
module_exit(kobj_test_exit);

