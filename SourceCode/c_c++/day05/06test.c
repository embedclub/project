/*************************************************************************
    > File Name: 06test.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月07日 星期五 20时05分13秒
    > Version: 1.0  
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int c(int x, int y);
int main(void) {
	int i, j, n = 13;
	printf("N = ");
	while (n > 12)
		scanf("%d", &n);  /* 控制输入正确的值以保证屏幕显示的图形正确 */
	for (i = 0; i <= n; i++) {
		for (j = 0; j < 12 - i; j++)
			printf(" ");
		for (j = 1; j < i + 2; j++)
			printf("%6d", c(i, j));
		printf("\n");
	}
}

int c(int x, int y) {
	int z;
	if ((y == 1) || (y == x + 1))
		return 1;
	z = c(x -1, y -1) + c(x -1, y);
	return(z);
}
