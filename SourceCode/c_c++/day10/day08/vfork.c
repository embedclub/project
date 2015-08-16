
#include "public.h"

int main()
{
	pid_t pid = vfork();
	if(pid > 0)
	{
		printf("我是父进程，创建的子进程:%d\n", pid);
	
	}
	else if (pid == 0)
	{
		printf("子进程执行结束!\n");
		exit(0);
		//exec(....)
	}
	else
	{
		perror("vfork failed!");
		return -1;
	}
	printf("父进程结束！\n");
	return 0;
	
}


