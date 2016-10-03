#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/list.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sun jack");
MODULE_DESCRIPTION("ListModule");
MODULE_ALIAS("List module");

//以上为内核模块的的头文件和模式固定的部分

struct student {
	char name[100];
	int num;
	struct list_head list;
};

//以上是定义包含有的struct list_head 结构的数据结构

struct student *pstudent;	//定义一个结构数组，用来存放数据，注意这里pstudent是数组指针，数组的大小由后面的kmalloc来分配！
struct student *tmp_student;	//遍历时临时用来存放指向pstudent[i]的指针
struct list_head student_list;	//定义链表头(是一个节点),这是一个list_head结构体的头结点
struct list_head *pos;		//指向头结点的一个指针，会在list_for_each中说明

int mylist_init(void)
{
	int i = 0;
	
	INIT_LIST_HEAD(&student_list);	//初始化链表头，注意参数是一个指针，用了&符号

	pstudent = kmalloc(sizeof(struct student)*5,GFP_KERNEL);	//为结构体数组分配空间，共有5个数组成员
	memset(pstudent, 0, sizeof(struct student)*5);	//初始化结构体数组

	for (i = 0; i < 5; i++)	//建立链表
	{
		sprintf(pstudent[i].name, "Student%d", i+1);	//初始化并显示学生姓名
		pstudent[i].num = i + 1;	////初始化学生号码
		//list_add(&(pstudent[i].list), &student_list);//将pstudent[i].list节点插入到student_list链表中，注意这里是从头结点处插入的，最后顺序为   5、4、3、2、1
		list_add_tail(&(pstudent[i].list), &student_list);//将pstudent[i].list节点插入到student_list链表中，注意这里是从尾部处插入的，最后顺序为  1、2、3、4、5

	}
	//这是一个for循环，所以需要加“{}”中括号
	list_for_each(pos, &student_list)//遍历链表，此函数指明pos是一个指向节点头的指针，前面已经定义了它的类型。遍历函数相当于一个for循环，{ }内为循环操作，没循环一次pos=&student_list+1！
	{
		tmp_student = list_entry(pos, struct student, list);//list_entry（提取数据结构）指针pos指向结构体struct student中的成员list，返回值为指向list所在的结构体的指针（起始地址）
		printk("<0>student%d name: %s\n", tmp_student->num, tmp_student->name);
	}//输出此结构体（结构数组其中的一个成员）的数据信息

	return 0;
}


void mylist_exit(void)//删除节点
{
	int i, n;
	/* 实验：将for换成list_for_each来遍历删除结点，观察要发生的现象，并考虑解决办法 会发生段错误，指针操作错误 */
//	for (i = 0; i < 5; i++)
//	{
//		list_del(&(pstudent[i].list));
//	}
//	list_for_each(pos, &student_list)
//	{
//		list_del(pos);
//	}
	list_for_each_safe(pos,n,&student_list) {
		list_del(pos);
		tmp_student = list_entry(pos,struct student,list);
		printk("num %d has removed from the list!\n",tmp_student->num);
	}	kfree(tmp_student);

	printk("Sun: has delete the list node!\n");	
	kfree(pstudent);//释放分配的内存
}

module_init(mylist_init);//内核模块模式固定的部分
module_exit(mylist_exit);//内核模块模式固定的部分
