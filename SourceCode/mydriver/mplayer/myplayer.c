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

	ret = execlp("mplayer","./mplayer","-ao","alsa:device=hw=1.0","-playlist","/playlist",NULL);
	
	if (ret < 0)
		printf("errror\n");

	return 0;
}
