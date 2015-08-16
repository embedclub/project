/*************************************************************************
    > File Name: rabbit.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月05日 星期三 22时03分34秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main() 
{ 
	long f1,f2; 
	int i; 
	f1=f2=1; 
	for(i=1;i<=20;i++) { 
		printf("%12ld %12ld",f1,f2); 
		if(i%2==0) printf("\n");
		f1=f1+f2; /*前两个月加起来赋值给第三个月*/ 
		f2=f1+f2; /*前两个月加起来赋值给第三个月*/ 
	}
	return 0;
} 

