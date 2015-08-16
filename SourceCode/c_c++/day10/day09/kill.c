
#include "public.h"
#include <signal.h>

void child(int signo)
{
	printf("进程%d捕获到信号:%d\n",
			getpid(), signo);
}
int main()
{
	int pid = fork();
	if(pid == 0)
	{
		/*子进程*/
		//signal(SIGUSR1, child);
		signal(SIGINT, child);
		while(1);
	}
	sleep(1);
	printf("父进程发送信号:%d\n", SIGUSR1);
	//kill(pid, SIGUSR1);
		signal(SIGINT, child);
	kill(pid, SIGINT);
	while(1);
	return 0;
}


