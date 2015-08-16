
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *task(void *p)
{
	int i = 0;
	for(; i<1000;  i++)
	{
		printf("%d ", i);
		fflush(stdout);
		if(200 == i) 
		{
			//pthread_exit((void *)i);
			exit(i);
		}
	}
}

int main()
{
	pthread_t id1;
	pthread_create(&id1, 0, task, 0);
	int res;
	pthread_join(id1, (void **)&res);
	printf("res=%d\n", res);

}
