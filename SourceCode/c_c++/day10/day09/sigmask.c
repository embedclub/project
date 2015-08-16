#include <signal.h>
#include "public.h"

void sig_func(int signo)
{
	printf("捕获到信号:%d\n", signo);
}

int main(void)
{
	signal(SIGINT, sig_func);
	signal(SIGQUIT, sig_func);
	signal(50, sig_func);
	printf("PID =%d\n", getpid());
	
	printf("面试前打个电话试试...\n");
	sleep(1000);
	printf("准备面试， 屏蔽信号....\n");
	/*准备要屏蔽的信号集*/
	sigset_t new;
	sigset_t old;
	sigemptyset(&new);
	sigemptyset(&old);
    sigaddset(&new, SIGINT);
	sigaddset(&new, SIGQUIT);
	sigaddset(&new, 50);
	/* 屏蔽信号 2 3 50*/
	sigprocmask(SIG_SETMASK, &new, &old);
	printf("面试过程中....\n");
	/*关键代码*/
    sleep(30);
	printf("面试结束，解除屏蔽\n");
   	/*解除屏蔽*/ 
	sigprocmask(SIG_SETMASK, &old, NULL);
	while(1);
}
