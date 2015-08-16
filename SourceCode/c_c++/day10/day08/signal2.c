
#include "public.h"
#include <signal.h>
void fa(int signum )
{
	printf("你发信号%d, 想杀死我？ 没可能\n", signum);
//	exit(0);
	//signal(SIGQUIT, SIG_IGN);
	signal(SIGQUIT, SIG_DFL);
	
}
int main()
{
	signal(SIGQUIT, fa);//注册一个信号处理函数
	while(1);
}


