
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int main()
{
	FILE *file = fopen("/etc/passwd", "r+");
	if(file == NULL)
	{
		//printf("fopen failed! errno =%d\n", errno);
		//printf("fopen failed:%s\n", 
		//		strerror(errno));
		//perror("fopen failed ");
		printf("fopen failed: %m\n");
	}
	else
	{
		printf("open successed!\n");
	}
#if 0
	file = fopen("/etc/passwd", "r");
	//if(file != NULL) //成功
	if(errno == 0)	//成功
 	{
		printf("open successed!\n");
	} 
	else
	{
		perror("open passwd failed ");
	}
#endif

	return 0;
}
