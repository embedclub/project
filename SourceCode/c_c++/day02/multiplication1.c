/*************************************************************************
    > File Name: multiplication1.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月04日 星期二 23时59分18秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void) { 
	int i,j,result; 
	printf("\n"); 
	for (i=1;i<10;i++) { 
		for(j=1;j<10;j++) { 
			result=i*j; 
			printf("%d*%d=%-3d",i,j,result);/*-3d表示左对齐，占3位*/ 
		} 
	printf("\n");/*每一行后换行*/ 
	}
	return 0;
} 

