
#include <signal.h>
#include "public.h"

void sig_func(int signum)
{
	printf("进程%d捕获到信号%d\n", 
			getpid(), signum);
}

int main(void)
{
	signal(SIGINT, sig_func);
	int res = sleep(10000);
	printf("res = %d\n", res);
	raise(SIGINT);
	pause();
	printf("aaaaa\n");	
}
