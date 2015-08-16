/*************************************************************************
    > File Name: 02test.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月07日 星期五 16时03分51秒
    > Version: 1.0  
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void) {
	int i, x, y, last = 1; /* 变量last保存求X的Y次方过程中的部分积的后三位 */
	printf("Input X and Y (X**Y):");
	scanf("%d**%d",&x, &y);
	for (i = 1; i <= y; i++) /* 将last乘X后对1000取模，即求积的后三位 */
		last = last  * x % 1000;							/* X自乘Y次 */
	printf("The last 3 digits of %d ** %d is: %d\n", x, y, last % 1000);/* 打印结果 */
}
