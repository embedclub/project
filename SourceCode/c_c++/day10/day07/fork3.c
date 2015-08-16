#include "public.h"

int i1 = 100;
int main()
{
	int i2 = 200;
	char *str = malloc(20);
	strcpy(str, "abcdefg");

	pid_t pid = fork();
	int i3 = 300;
	if(pid == -1)
	{
		perror("fork failed");
		return -1;
	}
	else if(pid == 0)
	{
		/*子进程*/
		i1 = 10;
		i2 = 20;
		i3 = 30;
		int i4 = 400;
		strcpy(str, "1234567");
		printf("in child i1 = %d\n", i1);
		printf("in child i2 = %d\n", i2);
		printf("in child i3 = %d\n", i3);
		printf("in child i4 = %d\n", i4);
		printf("in child str = %s\n", str);
		free(str);
		str = NULL;
	}	
	else
	{
		/*父进程*/
		sleep(1);
		printf("in parent i1 = %d\n", i1);
		printf("in parent i2 = %d\n", i2);
		printf("in parent i3 = %d\n", i3);
		//printf("in parent i4 = %d\n", i4);
		printf("in parent str = %s\n", str);
		free(str);
		str = NULL;
	}
	return 0;
}
