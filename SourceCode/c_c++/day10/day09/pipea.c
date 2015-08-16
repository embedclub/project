
#include "public.h"
#include <sys/stat.h>

int main()
{
	/*创建管道文件*/
    if(mkfifo("pipe", 0666) < 0)
	{
		perror("mkfifo failed");
		exit(-1);
	}
	/*写打开管道文件*/
    int fd = open("pipe", O_WRONLY);
	if(fd == -1)
	{
		perror("write open failed!");
		exit(-1);
	}
	/*向管道中写入数据*/
    int i = 0;
	for(; i<50; i++)
	{
		write(fd, &i, sizeof(i));
		printf("wrtie %d\n", i);
		sleep(1);
	}
	/*关闭管道*/
	close(fd);
	/*删除管道文件*/
    unlink("pipe");
}
