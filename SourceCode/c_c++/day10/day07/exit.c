
#include "public.h"

void at(void)
{
	printf("进程即将退出，我来做扫尾工作!\n");
}

void func()
{
	printf("调用exit准备退出进程!\n");
	//exit(0);
	//_exit(0);//_Exit(0);
	return ;
}

int main()
{
	/*约定当进程中执行exit()函数退出进程前，来调用
	     at 函数
     */
	atexit(at);
	printf("开始工作....\n");
	func();
	printf("这句话不会被打印!\n");
}


