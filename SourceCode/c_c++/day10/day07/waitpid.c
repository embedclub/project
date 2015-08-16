
#include "public.h"
#include <sys/wait.h>

int main()
{
	pid_t pid1 = 0;
	pid_t pid2 = 0;

	pid1 = fork();
	if(pid1 > 0)
	{
		pid2 = fork();
	}	
	//子进程一
    if(pid1 == 0)
	{
		printf("子进程一开始执行,PID=%d,睡3秒\n",
				getpid());
		sleep(3);
		printf("子进程一结束\n");
		exit(10);
		//return 10;
	}
	//子进程二
    if(pid2 == 0)
	{
		printf("子进程二开始执行,PID=%d,睡1秒\n",
				getpid());
		sleep(1);
		printf("子进程二结束\n");
		exit(20);
		//return 10;
	}
	//父进程
	printf("父进程等待子进程一结束\n");
 	int result = 0;
	waitpid(pid1, &result, 0);
	if(WIFEXITED(result))
	{
		printf("子进程一的返回值：%d\n",
				WEXITSTATUS(result));
	}
	printf("父进程结束\n");
}
