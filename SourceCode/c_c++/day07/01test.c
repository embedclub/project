/*************************************************************************
    > File Name: 01test.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月10日 星期一 11时03分36秒
    > Version: 1.0  
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void) {
	int i;
	for (i = 0; i <= 60; i++) {
		printf("\b\b\b%2d ", i);
		sleep(1);
	}
}
