
#include "public.h"

int main()
{
	printf("程序开始执行\n");
	pid_t pid = fork();
	printf("pid = %d, 程序执行结束\n",
			pid);

	return 0;
}

