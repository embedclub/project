/*************************************************************************
    > File Name: sort.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月06日 星期四 23时15分36秒
    > Version: 1.0  
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void) {
	int integer, i, max, min, sum;
	max = -32768;      /* 先假设当前的最大值max为C语言整形数的最小值 */
	min = 32767;	   /* 先假设当前的最小值min为C语言整形数的最大值 */
	sum = 0;
	for (i = 1; i <= 10; i++) {
		printf("Input number %d = ", i);
		scanf("%d", &integer);					/* 输入评委的评分 */
		sum += integer;									/* 计算总分 */
		if (integer > max) max = integer;  /* 通过比较筛选出其中的最高分 */
		if (integer < min) min = integer;  /* 通过比较筛选出其中的最低分 */
	}
	printf("Canceled max score: %d\nCanceled min score: %d\n", max, min);
	printf(" Average score: %d\n", (sum - max - min)/8);/* 输出结果 */
}
