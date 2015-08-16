/*************************************************************************
    > File Name: 01test.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月07日 星期五 15时08分36秒
    > Version: 1.0  
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void) {
	long i;
	int j;
	printf("Please input number:");
	scanf("%ld", &i);
	for (j = 999; j >= 100; j--) { /* 所求的约数的可能取值是从999到100，j从大到小 */
		if (i%j == 0) { /* 若是约数，则输出结果 */
			printf("The max factor with 3 digits in %ld is: %d.\n", i, j);
			break;
		}
	}
}
