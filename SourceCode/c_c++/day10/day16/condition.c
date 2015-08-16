
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

/*仓库*/
char data[5] = {0};
int rpos = 0;
int wpos = 0;
int size = 0; //仓库中现存产品个数
/*互斥量 保护共享资源data[] size*/
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full  = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;

/*打印仓库中的产品*/
void print()
{
	int tmp = rpos;
	int i = 0;
	printf("仓库中现有%d件产品： ", size);
	for(; i<size; i++)
	{
		if(tmp == 5)
		{
			tmp = 0;
		}
		printf("%c ", data[tmp++]);
	}
	printf("\n");
}
void *productor(void *arg)
{
	char c = 0;
	for(c='a'; c<='z'; c++)
	{
		//判断是否有权操作
		pthread_mutex_lock(&lock);
		/*如果仓库满*/
		while(size == 5)
		{
			/* 使当前线程暂停
               1 解锁，释放仓库的使用权力
			   2 挂起当前进程，使当前进程睡入full
                 对应的队列中去
			   3 等待仓库不满的信号到来 继续工作
			   4 唤醒时，首先去试图获取锁，如果获取
				 锁不成功继续阻塞
             */
			printf("生产者睡眠\n");
			pthread_cond_wait(&full, &lock);
			printf("生产者被唤醒\n");
		}
		/*仓库不满*/
		data[wpos++] = c;
		if(wpos==5)
		{
			wpos = 0;
		}
		size++;
		printf("push: %c\n", data[size-1]);
		print();
		//释放权力
		pthread_mutex_unlock(&lock);
		/*如果仓库非空则应该那些因为仓库为空而睡眠的线程*/
		pthread_cond_signal(&empty);
		sleep(rand()%3);
	}
}
void *customer(void *arg)
{
	int i = 0;
	for(; i<52; i++)
	{
		pthread_mutex_lock(&lock);
		while(size == 0) //仓库为空
		{
			/* 暂停当前线程
               1 释放锁
			   2 睡眠
			   3 等待被唤醒
               4 如被唤醒先来加锁
             */
			printf("消费者睡眠\n");
			pthread_cond_wait(&empty, &lock);
			printf("消费者被唤醒\n");
		}
		/*仓库非空*/
		size--;
		printf("pop: %c\n", data[rpos++]);
		if(rpos == 5)
		{
			rpos = 0;
		}
		print();
		pthread_mutex_unlock(&lock);
		/*唤醒因为仓库满而睡眠的线程*/
		pthread_cond_signal(&full);
		sleep(rand()%6);
	}
}
int main()
{
	pthread_t ids[3];
	srand(time(0));
	setbuf(stdout, NULL);
	/*生产者线程*/
	pthread_create(&ids[0], 0, productor, 0);	
	pthread_create(&ids[2], 0, productor, 0);	
	/*消费者线程*/
	pthread_create(&ids[1], 0, customer, 0);

	pthread_join(ids[0], 0);
	pthread_join(ids[1], 0);
	pthread_join(ids[2], 0);

	return 0;
}



