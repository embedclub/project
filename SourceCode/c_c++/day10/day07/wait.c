
#include "public.h"
#include <sys/wait.h>

int main()
{
#if 0
    /* 验证父进程没有子进程时调用wait的结果*/
	int result = 0;
	pid_t pid = wait(&result);
	if(pid == -1)
	{
		perror("wait failed");
	}
#endif
	pid_t pid = fork();
	if(pid == 0)
	{
		printf("子进程开始运行，即将进入睡眠\n");
		sleep(10);
		printf("子进程即将结束\n");	
		exit(100);//n介于 0~255之间
	}
    printf("父进程正在运行，子进程PID=%d\n",pid);
    printf("父进程等待子进程结束\n");
	int result = 0;
	//如果子进程未结束，该函数阻塞等待
	pid_t res = wait(&result);
	printf("等到结束的子进程是：%d\n", res);
	//printf("result=%d\n", result);
	if(WIFEXITED(result))//正常退出
	{
		printf("子进程的返回值=%d\n",
				WEXITSTATUS(result));
	}
	
	return 0;
}

