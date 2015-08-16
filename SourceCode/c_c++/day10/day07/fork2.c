
#include "public.h"

int main()
{
	printf("程序开始执行\n");
	pid_t pid = fork();
	if(pid == 0)
	{
		printf("我是子进程，PID=%d,我的父进程是：%d\n",
				getpid(),
				getppid());
		printf("我负责播放歌曲.... \n");
	}
	else if(pid > 0)
	{
		printf("我是父进程，PID=%d,我的子进程是:%d\n",
				getpid(),
				pid);
		printf("我负责启动游戏.....\n");
	}
	else
	{
		perror("fork failed");
		return -1;
	}
	while(1);	
	printf("%d进程结束执行\n", getpid());
	return 0;
}
