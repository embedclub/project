#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc , char **argv)
{
	int fd1 = open("a.txt", O_RDONLY);
	int fd2 = open("b.txt", O_RDWR|O_CREAT|O_TRUNC,
					0666);
	char buf[100] = {0};
	int res = 0;
	while((res=read(fd1,buf,sizeof(buf))) > 0)
	{
		write(fd2, buf, res);
	}
	close(fd1);
	close(fd2);

}



