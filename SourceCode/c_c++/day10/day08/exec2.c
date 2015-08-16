#include "public.h"

int main()
{
	pid_t pid = vfork();
	if(pid > 0)
	{
		/*父进程*/
		printf("我是父进程，创建的子进程：%d\n",pid);
	}
	else
	{
		/*子进程*/
	    execl("./a.out", "a.out",  NULL);
		/*覆盖当前进程的代码段*/
		printf("子程序结束！\n");
	}

	printf("父进程结束！\n");
	return 0;

}
