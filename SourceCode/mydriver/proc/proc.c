/*****************************************************************
 ********                  proc文件系统                   ********
 * 时间： 2016.10.03  16.30
 * 功能： proc文件系统学习文件
 * 作者： Sun Jack
 * 验证平台：已经在tina2.0的源码 + R16的开发板上使用成功
 * 编译方式：采用在内核里面直接添加代码，并编译成模块测试
 * 存在问题：
 ***                                                           ***
 *****************************************************************/


#define __KERNEL__
#define MODULE

#include <linux/module.h> 
#include <linux/kernel.h> 
#include <linux/init.h>
#include <linux/proc_fs.h> /* Necessary because we use the proc fs */
#define procfs_name "proctest"

struct proc_dir_entry *Our_Proc_File;

int procfile_read(char *buffer,
        char **buffer_location,
        off_t offset, int buffer_length, int *eof, void *data)
{
        int ret;

        ret = sprintf(buffer, "HelloWorld!\n");
        return ret;
}

int proc_init()
{
        Our_Proc_File = create_proc_entry(procfs_name, 0644, NULL);//不填父目录，会自动创建在/proc目录下
        if (Our_Proc_File == NULL) {
                remove_proc_entry(procfs_name, NULL);
                printk(KERN_ALERT "Error: Could not initialize /proc/%s\n",
                        procfs_name);
                return -ENOMEM;
        }
        Our_Proc_File->read_proc = procfile_read;
//        Our_Proc_File->owner = THIS_MODULE;
        Our_Proc_File->mode = S_IFREG | S_IRUGO;
        Our_Proc_File->uid = 0;
        Our_Proc_File->gid = 0;
        Our_Proc_File->size = 37;
        printk("/proc/%s created\n", procfs_name);
        return 0; 
}

void proc_exit()
{
        remove_proc_entry(procfs_name, NULL);
        printk(KERN_INFO "/proc/%s removed\n", procfs_name);
}

module_init(proc_init);
module_exit(proc_exit);
