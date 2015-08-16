
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#define MAX_PTHREAD_NUM 20
#define LIMITED_NUM 10

sem_t limited;

void *proc(void *arg)
{
	int num = (int)arg;
	printf("第%d个线程启动，并申请连接数据库\n",
			num);
	sem_wait(&limited); //-1
	printf("第%d个线程连接数据库成功...\n", num);
	srand(pthread_self());
	//srand(time(0));
	//printf("time(0) = %d\n", time(0));
	int random = rand()%30;
	printf("random=%d\n", random);
	sleep(random);
	printf("第%d个线程连接数据库结束\n", num); 
	sem_post(&limited); // +1
	return NULL;

}
int main()
{
	int i = 0;
	pthread_t ids[MAX_PTHREAD_NUM] = {0};

	sem_init(&limited, 0, LIMITED_NUM);
		
	for(; i<MAX_PTHREAD_NUM; i++)
	{
		pthread_create(&ids[i], 0,proc,(void *)i);
		pthread_detach(ids[i]);
	}
	while(1);
	sem_destroy(&limited);
	return 0;
}
