
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
void * task(void *arg)
{
	printf("我是子线程id=%lu\n", pthread_self());
}

int main()
{
	/*创建线程*/
	pthread_t id;
	int res = pthread_create(&id, NULL, task, 0);
	if(res)
	{
		printf("pthread_create failed: %s\n",
				strerror(res));
		exit(-1);
	}
	else
	{
		printf("create successed id=%lu\n", id);;
	}
	printf("主线程ID=%lu\n", pthread_self());
	sleep(1);
	return 0;
}

