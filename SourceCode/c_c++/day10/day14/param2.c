#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *task1(void *arg)
{
	sleep(3);
	printf("传入的 x=%d\n",*((int *)arg));
	//printf("传入的 x=%d\n",(int)arg);
}
double r = 2.5;
void *task2(void *arg)
{
	sleep(1);
	/*求圆的面积*/
	printf("area = %lf\n", 3.14*r*r);
	return NULL;
}

int main()
{
	pthread_t id1 = 0;
	pthread_t id2 = 0;
	int x = 100;
	int y = 123;
	int z = 456;
	pthread_create(&id1, 0, task1, &x);
	//pthread_create(&id1, 0, task1, (void *)x);
	pthread_create(&id2, 0, task2, 0);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	return 0;
}
