
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main(void)
{
	printf("cat /proc/%d/maps\n", getpid());
	getchar();
	void *p = sbrk(0);//获取初始位置
    //void *p1 = sbrk(4);
    brk(p+4);//分配4个字节  sbrk(4)
	brk(p+8);//分配4个字节
	brk(p+4); //释放4个字节空间
	printf("%p\n", p);
	getchar();
    *((int *)p) = 123;
	brk(p);
	return 0;
}



