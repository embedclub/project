
#include "public.h"

int main()
{
	int fd = open("tmp.txt", O_RDWR|O_CREAT, 0666);
	if(fd > 0)
	{
		printf("open tmp.txt successed!\n");
	}
	char str[100] = "abcdefg";
	int count = write(fd, str,strlen(str));
	printf("写入了%d个字节",count);
   	getchar(); 
	unlink("tmp.txt");
	getchar();
	close(fd);
}

