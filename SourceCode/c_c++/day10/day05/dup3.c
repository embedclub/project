
#include "public.h"
#include <fcntl.h>

int main()
{
	int fd1 = open("dup1.txt", 
					O_RDWR|O_CREAT|O_CREAT,
					0644);
	printf("fd1=%d\n", fd1);
	int fd2 = open("dup2.txt", 
					O_RDWR|O_CREAT|O_CREAT,
					0644);
	printf("fd2=%d\n", fd2);
	/*fd3 和fd1对应了同一个文件表，
		使用同一个offset
     */
	int fd3 = fcntl(fd1, F_DUPFD, fd2);
	printf("fd3=%d\n", fd3);
	
	char *text = "123";
	write(fd1, text, strlen(text));
	text = "456";
	write(fd2, text, strlen(text));
	text = "789";
	write(fd3, text, strlen(text));
	close(fd1);
	close(fd2);
	close(fd3);	
	return 0;

}

