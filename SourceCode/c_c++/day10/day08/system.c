
#include "public.h"

int main()
{
	printf("start...\n");
	system("ls *.c >a.txt");
#if 0
	int pid = fork();
	if(pid == 0)
	{
		execlp("bash", "bash", "-c",
				"ls *.c >a.txt", NULL);
		exit(127);
	}
	int status = 0;
	waitpid(pid, &status, 0);
	/*获取子进程退出状态和退出码*/
#endif
}
