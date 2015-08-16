#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

unsigned int count = 0;
/*1 定义*/
sem_t sem;
void *func(void *arg)
{
	unsigned int i = 0;
	for(; i<100000000; i++)
	{
		/*3 加锁*/
		sem_wait(&sem);
		/*4  操作共享资源*/
		++count;
		/*5 解锁*/
		sem_post(&sem);
	}
	return NULL;
}

int main()
{
	printf("%d\n", getpid());
	int i = 0;
	pthread_t ids[3];
	/*2 初始化*/
	sem_init(&sem, 0, 1);
	pthread_create(&ids[0], NULL, func, NULL);
	pthread_create(&ids[1], NULL, func, NULL);
	pthread_create(&ids[2], NULL, func, NULL);
	pthread_join(ids[0], NULL);
	pthread_join(ids[1], NULL);
	pthread_join(ids[2], NULL);
	printf("count = %u\n", count);

	/*6 销毁锁*/
	sem_destroy(&sem);
}
