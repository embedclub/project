
#include "public.h"
#include <sys/stat.h>

int main()
{
	/*读打开管道文件*/
    int fd = open("pipe", O_RDONLY);
	if(fd == -1)
	{
		perror("read  open failed!");
		exit(-1);
	}
	/*从管道中读取数据*/
    int i = 0;
	int x = 0;
	for(; i<50; i++)
	{
		read(fd, &x, sizeof(x));
		fflush(stdout);
		printf("%02d ", x);
	}
	/*关闭管道*/
	close(fd);
}
