/*************************************************************************
    > File Name: circle.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月06日 星期四 16时55分30秒
    > Version: 1.0  
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<math.h>
int main(void) {
	double y;
	int x, m;
	for (y = 10; y >= -10; y--) {
		m = 2.5 * sqrt(100 - y * y);
		for (x = 1; x < 30 - m; x++)
			printf(" ");
		printf("*");
		for (; x < 30 + m; x++)
			printf(" ");
		printf("*\n");
	}
	return 0;
}
