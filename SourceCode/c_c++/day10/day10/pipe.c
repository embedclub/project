
#include "public.h"

int main()
{
	/*创建管道*/
	//int *pipefd = malloc(8);
	//pipe(pipefd);
	int fd[2];
	pipe(fd);
	pid_t pid = fork();
	if(pid > 0)	
	{
		/*父进程 写，关闭读*/
		close(fd[0]);
		int i = 0;
		for(i=100; i<=120; i++)
		{	
			write(fd[1], &i, sizeof(i));
			sleep(1);
		}		
		/*关闭写端*/
		close(fd[1]);
		exit(0);
	}
	/*子进程 读 关闭写端*/
	close(fd[1]);
	int i = 0;
	int x = 0;
	for(; i<=20; i++)
	{
		read(fd[0], &x, sizeof(x));
		printf("%d ", x);
		fflush(stdout);
	}
	close(fd[0]);//关闭读端
}
