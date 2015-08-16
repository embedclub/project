#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *task1(void *arg)
{
	sleep(3);
	printf("传入的 x=%d\n",*((int *)arg));
	//printf("传入的 x=%d\n",(int)arg);
	return NULL;
}
double r = 2.5;
double result = 0.0;
void *task2(void *arg)
{
	double tmp = *((double *)arg);
	*((double *)arg)  = 3.14 * tmp * tmp;
#if 0
	static double res = 0.0;
	sleep(1);
	/*求圆的面积*/
	res = 3.14 * r * r;
	result = res;
	printf("area = %lf\n", res);
	return (void *)&res;
#endif 
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
	double radius = 3.5;
	pthread_create(&id2, 0, task2,(void *)&radius);
	pthread_join(id1, NULL);

	double *tmp = NULL;
	//pthread_join(id2, (void **)&tmp);
	//printf("在主线程中获取到的结果=%lf\n",*tmp);	
	//printf("在主线程中获取到的结果=%lf\n",result);	
	pthread_join(id2, NULL);
	printf("在主线程中获取到的结果=%lf\n",radius);	
	return 0;
}
