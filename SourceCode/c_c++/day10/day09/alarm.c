
#include "public.h"
#include <signal.h>
void sigalrm(int signum)
{
	printf("收到SIGALRM信号！\n");
	exit(0);
}
int main()
{
	signal(SIGALRM, sigalrm);
	int remain = alarm(10);
	printf("定时10s....\n");
	printf("睡眠2s...\n");
	sleep(2);	
	/*取消定时*/
	remain = alarm(0);
	printf("取消定时，剩余%ds\n", remain);
	//remain = alarm(3);
	//printf("定时3s，剩余%ds\n", remain);
	while(1);
	return 0;
}
