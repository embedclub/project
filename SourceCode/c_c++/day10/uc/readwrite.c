#include <stdio.h>
#include <stdlib.h>

#ifndef STD
#include <unistd.h>
#include <fcntl.h>
#endif

int main()
{
#if STD
	FILE *file = fopen("a.txt", "w");
	if(file == NULL)
	{
		perror("fopen");
		return -1;
	}
	printf("open successed!\n");
	int i = 0;
	for(; i<1000000; i++)	
	{
		fwrite(&i, sizeof(int), 1, file);
	}
	fclose(file);
#else
	int fd = open("a.txt", O_RDWR|O_CREAT|O_EXCL,
					 0666);
	if(fd == -1)
	{
		perror("open");
		return -1;
	}
	printf("fd = %d\n", fd);
	int i = 0;
	int buf[1000] = {0};
	for(; i<1000000; i++)
	{
		/*0 999
		  1000 1999
          2000 2999
         */
		buf[i%1000] = i;
		if(i%1000 == 999)
		{
			write(fd, buf, sizeof(int)*1000);
		}
	}
	close(fd);
#endif
	return 0;
}


