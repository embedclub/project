
#include <stdio.h>
#include <pthread.h>
void *task(void *arg)
{
	int i = 0;
	for(; i<1000; i++)
	{
		printf("%d ", i);
		fflush(stdout);
		usleep(100000);
	}
	printf("\n");
	return  (void *)i;
}

int main()
{
	pthread_t id1;
	pthread_create(&id1, 0, task, 0);
	pthread_detach(id1); //让线程处于分离状态
	int i = 0;
	for(; i<50; i++)
	{
		printf("A ");
		fflush(stdout);
		usleep(100000);
	}
	printf("\n");
	pthread_join(id1, 0);	

}
