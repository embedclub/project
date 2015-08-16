
#include "public.h"

int main()
{
	int fd_null = open("/dev/null", O_RDWR);
	dup2(fd_null, STDOUT_FILENO);
  dup2(fd_null, 2);//将标准出错由屏幕改为/dev/null
	
	printf("helloworld!\n");
	int fd = open("abc.txt", O_RDWR);
	if(fd < 0)
	{
		perror("open failed!");
		return -1;
	}
	return 0;	
}
