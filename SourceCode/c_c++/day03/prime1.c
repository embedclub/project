/*************************************************************************
    > File Name: prime1.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月05日 星期三 23时03分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include "math.h" 
int main() { 
	int m,i,k,h=0,leap=1; 
	printf("\n"); 
	for(m=101;m<=200;m++) { 
		k=sqrt(m+1); 
		for(i=2;i<=k;i++) 
			if(m%i==0) {
				leap=0;break;
			} 
		if(leap) {
			printf("%-4d",m);
			h++; 
			if(h%10==0) 
			printf("\n"); 
		} 
			leap=1; 
	} 
	printf("\nThe total is %d",h); 
} 

