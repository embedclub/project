
#include "public.h"

int main()
{
	printf("当前进程PID=%d\n", getpid());
	printf("当前进程的父进程PID=%d\n", getppid());

	return 0;
}

