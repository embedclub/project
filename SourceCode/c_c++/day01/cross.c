/*************************************************************************
    > File Name: cross.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月02日 星期日 20时46分13秒
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
	int x, m, n, yy;
	for (yy = 0; yy <= 20; yy++) {	/* 对于每一个y坐标进行计算并在一行中打印图形*/
		y = 0.1 * yy;				/* */
		m = acos(1 - y) * 10;		/* */
		n = 45 * (y - 1) + 31;		/* */
		for (x = 0; x <= 62; x++)
			if (x == m && x == n)
				printf("+");
			else if (x == n)
				printf("+");
			else if (x == m || x == 62 - m)
				printf("*");
			else
				printf(" ");
		printf("\n");
	}
	return 0;
}
