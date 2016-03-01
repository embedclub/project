
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd = open("b.bin", O_RDWR|O_CREAT|O_TRUNC,
				   0664);	
	if(fd == -1)
	{
		perror("open failed!");
		return -1;
	}
	char *str = "雨好大啊！";
	int count = write(fd, str, strlen(str));
	printf("成功写入b.bin文件%d个字节\n", count);
	close(fd);
	
	fd = open("b.bin", O_RDONLY);
	char buf[100] = {0};
	count = read(fd, buf, count);
	printf("从文件b.bin中读取了%d个字节：%s\n",
			count, buf);
	close(fd);
	return 0;
}

