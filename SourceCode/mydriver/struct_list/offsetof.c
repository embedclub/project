/*
 *container_of宏分为两部分，

第一部分：const typeof( ((type *)0)->member ) *__mptr = (ptr);

通过typeof定义一个member指针类型的指针变量__mptr，（即__mptr是指向member类型的指针），并将__mptr赋值为ptr。

第二部分： (type *)( (char *)__mptr - offsetof(type,member) )，通过offsetof宏计算出member在type中的偏移，然后用member的实际地址__mptr减去偏移，得到type的起始地址，即指向type类型的指针。

第一部分的目的是为了将统一转换为member类型指针。
 */

#include <stdio.h>
#include <stdlib.h>

#define NAME_STR_LEN  32

#define offsetof(type, member) (size_t)&(((type*)0)->member)

#define container_of(ptr, type, member) ({ \
        const typeof( ((type *)0)->member ) *__mptr = (ptr); \
        (type *)( (char *)__mptr - offsetof(type,member) );})

struct list_head {
	struct list_head *next, *prev;	
};

typedef struct student_info
{
    int  id;
    char name[NAME_STR_LEN];
    int  age;
}student_info;


int main()
{
    size_t off_set = 0;
    off_set = offsetof(student_info, id);
    printf("id offset: %u\n",off_set);
    off_set = offsetof(student_info, name);
    printf("name offset: %u\n",off_set);
    off_set = offsetof(student_info, age);
    printf("age offset: %u\n",off_set);
    student_info *stu = (student_info *)malloc(sizeof(student_info));
    stu->age = 10;
    student_info *ptr = container_of(&(stu->age), student_info, age);
    printf("age:%d\n", ptr->age);
    printf("stu address:%p\n", stu);
    printf("ptr address:%p\n", ptr);
    return 0;
}
