/*************************************************************************
    > File Name: 02test.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月08日 星期六 18时33分29秒
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
	int i, j, k, c;
	for (i = 1; i <= 9; i++)	/* i:车牌号前二位的取值 */
		for (j = 0; j <= 9; j++) /* j:车号后二位的取值 */
			if (i != j) {   /* 判断两位数字是否相异 */
				k = i * 1000 + i * 100 + j * 10 + j; /* 计算出可能的整数 */
				for (c = 31; c * c < k; c++);	/* 判断该数是否为另一整数的平方 */
				if (c * c == k)
					printf("Lorry--No. is %d.\n", k);   /* 若是，打印结果 */
			}
}
