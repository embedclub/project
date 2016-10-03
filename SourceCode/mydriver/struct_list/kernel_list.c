#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/list.h>

MODULE_LICENCE("GPL");
MODULE_AUTHOR("LUOTAIJIA");

#define N 10
struct numlist {
    int num;
    struct list_head list;
};

struct numlist numhead;

static int __init doublelist_init(void)
{
    //初始化头结点
    struct numlist * listnode; //每次申请链表结点时所用的指针
    struct list_head * pos;
    struct numlist * p;
    int i;

    printk("doublelist is starting...\n");
    INIT_LIST_HEAD(&numhead.list);
    /* 
     * static inline void INIT_LIST_HEAD(struct list_head *list)
     * {
     * list->next = list;
     * list->prev = list;
     * }
     */

    //建立N个结点，依次加入到链表当中
    for (i=0; i<N; i++) {
        listnode = (struct numlist *)kmalloc(sizeof(struct numlist), GFP_KERNEL);
        //void *kmalloc(size_t size, int flages) 
        //分配内存，size 要分配内存大小，flags 内存类型
        listnode->num = i+1;
        list_add_tail(&listnode->list, &numhead.list);
        printk("Node %d has added to the doublelist...\n", i+1);
    }
    //遍历链表
    i = 1;
    list_for_each(pos, &numhead.list) {
        p = list_entry(pos, struct numlist, list);
        printk("Node %d's data: %d\n", i, p->num);
        i++;
    }
    return 0;
}

static void __exit doublelist_exit(void)
{
    struct list_head *pos, *n;
    struct numlist *p;
    int i;

    //依次删除N个结点
    i = 1;
    list_for_each_safe(pos, n, &numhead.list) {
        //为了安全删除结点而进行的遍历
        list_del(pos); //从链表中删除当前结点
        p = list_entry(pos, struct numlist, llist); 
        //得到当前数据结点的首地址，即指针
        kfree(p); //释放该数据结点所占空间
        printk("Node %d has removed from the doublelist...\n", i++);
    }
    printk("doublelist is exiting...\n");
}

module_init(doublelist_init);
module_exit(doublelist_exit);

