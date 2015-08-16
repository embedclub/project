
#include "public.h"

int main()
{
	int fd1 = open("dup.txt", 
					O_RDWR|O_CREAT|O_TRUNC,
					0664);
	if(fd1 == -1)
	{
		perror("open failed");	
		return -1;	
	}
	printf("fd1 = %d\n", fd1);
	
	int fd2 = dup(fd1);
	if(fd2 == -1)
	{
		perror("dup failed");
		return -1;
	}
	printf("fd2 = %d\n", fd2);

	int fd3 = dup2(fd1, 100);
	printf("fd3=%d\n", fd3);

	const char *text = "Hello,World!";
	write(fd1, text, strlen(text));//offset+strlen
	
	lseek(fd2,  -6, SEEK_CUR);
	//lseek(fd2, 6, SEEK_SET);
	
	text = "Linux";
	write(fd3, text, strlen(text));
}
