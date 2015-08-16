/*************************************************************************
    > File Name: guess.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月03日 星期一 23时25分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<math.h>
int main(void) {
	int i, k, j;
	for (i = 0; ; i++) {
		k = sqrt(i + 100);
		j = sqrt(i + 168);
		if (k * k == (i + 100) && j * j == (i + 168) ) {
			printf("%d\n", i);
			break;
		}
	}
}
