/*************************************************************************
    > File Name: combination2.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月03日 星期一 22时11分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void) { 
	int i, j, k, m; 
	printf("\n"); 
	for(i=1;i<5;i++)  /*以下为三重循环*/ 
		for(j=1;j<5;j++) 
			for (k=1;k<5;k++) { 
				if (i!=k&&i!=j&&j!=k) /*确保i、j、k三位互不相同*/{
					printf("%d,%d,%d\n",i,j,k); 
					m++;
				}
			}
	printf("the number of result is %d\n", m);
	return 0;
} 
