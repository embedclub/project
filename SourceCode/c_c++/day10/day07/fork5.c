
#include "public.h"

int main()
{
	printf("父进程%d开始执行，并创建子进程\n",
			getpid());
	int pid = fork();
	if(pid == 0)
	{
		printf("子进程%d被创建并开始执行，子进程的父进程是%d\n", getpid(), getppid());
		printf("子进程进入睡眠状态\n");
		sleep(3);
		printf("子进程的父进程是：%d\n",getppid());		   printf("子进程结束！\n");
	}
	else
	{
		printf("父进程继续运行....\n");
		sleep(1);
		printf("父进程结束\n");
	}
}
