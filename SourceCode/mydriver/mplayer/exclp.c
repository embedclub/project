#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main()
{
	int ret;
	
	pid_t pid;
	
	pid = fork();

	if (pid < 0)
	{
		perror("error!\n");
	}
	if (pid == 0)
	{
	printf("child is here!\n");
	//ret = execlp("ls","ls","-a","-l",NULL);
	ret = execlp("./mplayer","./mplayer","-ao","alsa:device=hw=1.0","-playlist","/playlist",NULL);

	if (ret < 0)
		printf("errror\n");
	}

	else 
	{
		printf("hello word!\n");
		sleep(2);
		printf("parent exit!\n");
	}
	return 0;
}
