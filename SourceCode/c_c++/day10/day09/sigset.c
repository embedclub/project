
#include "public.h"
#include <signal.h>

int main(void)
{
	sigset_t set;
	printf("sigset_t size = %d\n", sizeof(set));
	/*初始化set*/
	//sigfillset(&set);
	sigemptyset(&set);	
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGQUIT);
	if(sigismember(&set, SIGINT))
	{
		printf("there is SIGINT in set!\n");
	}
	else
	{
		printf("there is not SIGINT in set!\n");
	}
	sigdelset(&set, SIGQUIT);
	if(sigismember(&set, SIGQUIT))
	{
		printf("there is SIGQUIT in set!\n");
	}
	else
	{
		printf("there is not SIGQUIT in set!\n");
	}
}

