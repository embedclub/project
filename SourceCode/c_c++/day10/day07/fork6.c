
#include "public.h"

int main(void)
{
	printf("%d进程：我调用fork()了..\n", getpid());
	pid_t pid = fork();
	if(pid == 0)
	{
		printf("%d进程：我是%d的子进程，即将成为僵尸...\n", getpid(), getppid());
	
	}
	else
	{
		sleep(1);
		printf("%d进程:我是%d的父进程\n",
				getpid(),
				pid);
		printf("执行ps -elf | grep %d\n", pid);
		getchar();
	}	
	return 0;
}
