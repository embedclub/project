/*************************************************************************
    > File Name: prime.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月05日 星期三 22时36分52秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<math.h>
int main(void) {
	int i, j, m, leap = 1, k = 0;
	for (i = 101; i <= 200; i++) {
		m = sqrt(i);
		for (j = 2; j <= m; j++) {
			if (i % j == 0) {
				leap = 0;  //标志位
				break;
			}
		}
		if (leap) {
			printf("%-4d", i);
			k++;
			if (k % 10 == 0) {
				printf("\n");
			}
		}
			leap = 1;
	}
	printf("\nThe total is %d\n", k);
}
