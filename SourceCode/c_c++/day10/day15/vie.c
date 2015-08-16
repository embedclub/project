#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

unsigned int count = 0;
/*1 定义*/
pthread_mutex_t lock;

void *func(void *arg)
{
	unsigned int i = 0;
	for(; i<100000000; i++)
	{
		/*3 加锁*/
		pthread_mutex_lock(&lock);
		/*4  操作共享资源*/
		++count;
		/*5 解锁*/
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

int main()
{
	int i = 0;
	pthread_t ids[3];
	/*2 初始化*/
 	pthread_mutex_init(&lock, NULL);
	pthread_create(&ids[0], NULL, func, NULL);
	pthread_create(&ids[1], NULL, func, NULL);
	pthread_create(&ids[2], NULL, func, NULL);
	pthread_join(ids[0], NULL);
	pthread_join(ids[1], NULL);
	pthread_join(ids[2], NULL);
	printf("count = %u\n", count);

	/*6 销毁锁*/
	pthread_mutex_destroy(&lock);
}
