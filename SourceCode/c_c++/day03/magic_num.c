/*************************************************************************
    > File Name: magic_num.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月05日 星期三 23时14分52秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main() { 
	int i,j,k,n; 
	printf("'water flower'number is:"); 
	for(n=100;n<1000;n++) { 
		i=n/100;/*分解出百位*/ 
		j=n/10%10;/*分解出十位*/ 
		k=n%10;/*分解出个位*/ 
		if(i*100+j*10+k==i*i*i+j*j*j+k*k*k) { 
			printf("%-5d",n); 
		} 
	} 
	printf("\n");
	return 0;
} 

