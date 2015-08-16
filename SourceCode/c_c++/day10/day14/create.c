
#include <stdio.h>
#include <pthread.h>

void *task(void *arg)
{
	//printf("arg = %d\n", arg);
	while(1)
	{
		printf("============================\n");
		sleep(1);
	}
	return (void *)0;
}


int main()
{
	pthread_t id;
	pthread_create(&id, 0, task, 0);
	
	while(1)
	{
		printf("+++++++++++++++++++++++++++\n");
		sleep(1);
	}
}



