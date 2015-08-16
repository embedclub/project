
#include "public.h"

int main()
{
	int fd = open("a.txt", O_RDWR|O_CREAT, 0666);
	if(fd == -1)
	{
		perror("open failed");
		return -1;
	}
	pid_t pid = fork();
	if(pid == 0)
	{
		/*子进程*/
		char c ;
		for(c='A'; c<='Z'; c++)
		{
			fsync(fd);
			write(fd, &c,1);
			fsync(fd);
			sleep(2);
		}
		close(fd);
	}	
	else 
	{
		/*父进程*/
		char c ;
		for(c='a'; c<='z'; c++)
		{
			fsync(fd);
			write(fd, &c, 1);
			fsync(fd);
			sleep(2);
		}
		close(fd);
	}
	return 0;
}
