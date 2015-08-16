
#include "public.h"
#include <signal.h>
#include <time.h>

void sigalrm(int signum)
{
	/*获取秒差*/
	time_t t = time(NULL);
	/*转秒差为时分秒的形式*/
    struct tm *lt = localtime(&t);	
	fflush(stdout);
	printf("\r%2d:%2d:%2d",lt->tm_hour, lt->tm_min,
						 lt->tm_sec);
	alarm(1);
}

int main(void)
{
	signal(SIGALRM, sigalrm);
	/*1s后当前进程会收到SIGALRM*/
	alarm(1);
	while(1);
	return 0;
}


