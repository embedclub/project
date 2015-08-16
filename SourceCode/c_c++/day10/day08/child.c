
#include "public.h"
#include <signal.h>
void fa(int signum)
{
	printf("捕获到信号%d\n", signum);
}
int main()
{
	if(signal(SIGINT, fa) == SIG_ERR)
	{
		perror("signal failed");
		exit(-1);
	}
	if(signal(SIGQUIT, fa) == SIG_ERR)
	{
		perror("signal failed");
		exit(-1);
	}
	pid_t pid = fork();
	if(pid == 0)
	{
		printf("子进程PID=%d\n", getpid());
		//signal(SIGINT, SIG_DFL);
		while(1);
	}
	printf("父进程结束\n");
}
