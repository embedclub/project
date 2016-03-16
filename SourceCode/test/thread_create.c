/***********************************************
 * 函数的功能：用于实现输出，线程1,2,3在运行
 * modified by Scc
 * time:2016.03.16
 * version: 1.0
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//全局变量定义
int n = 1;
//线程任务一
void *task1(void *arg)
{
	//sleep(3);
	printf("I am thread %d\n", n);
    return NULL;
}
//线程任务二
void *task2(void *arg)
{
//	sleep(1);
    n++;	
	printf("I am thread %d\n", n);
	return NULL;
}
//线程任务三
void *task3(void *arg)
{
//	sleep(1);
    n++;
	printf("I am thread %d\n", n);
	return NULL;
}
//主函数入口，带参数
int main(int argc, char *argv[])
{
    //线程id定义
	pthread_t id1 = 0, id2 = 0, id3 = 0;
    //线程创建函数，属于系统调用，不是库函数调用
	pthread_create(&id1, 0, task1, &n);
	pthread_create(&id2, 0, task2, &n);
    pthread_create(&id3, 0, task3, &n);
    //用于等待某个线程退出的函数
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	pthread_join(id3, NULL);

	return 0;
}
