
#include "public.h"

int main()
{
	int fd = open("tmp.txt", O_RDWR);
	if(fd > 0)
	{
		printf("打开文件成功!\n");
	}
	getchar();
	char buf[100] = {0};
	int count = read(fd, buf,100);
	printf("read from tmp.txt:%s\n", buf);
	close(fd);
	return 0;
}

