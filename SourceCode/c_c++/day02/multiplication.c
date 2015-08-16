/*************************************************************************
    > File Name: multiplication.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月04日 星期二 23时50分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main() {
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = i; j <= 9; j++)
			printf("%d x %d = %-3d  ", i, j, i * j);//第三个参数如果使用%d的话，输出结果不对其，比较丑。
		printf("\n");
	}
}
