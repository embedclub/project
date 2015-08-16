/*************************************************************************
    > File Name: 03test.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月07日 星期五 17时04分38秒
    > Version: 1.0  
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void) {
	int a, count = 0;
	for (a = 5; a <= 100; a += 5) {
		count++;
		if (!(a % 25))
			count++;
	}
	printf("The number of 0 in end of 100! is: %d.\n", count);
}
