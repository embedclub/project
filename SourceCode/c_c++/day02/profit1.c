/*************************************************************************
    > File Name: profit1.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月03日 星期一 22时54分57秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main() { 
	long int i; 
	int bonus1,bonus2,bonus4,bonus6,bonus10,bonus; 
	scanf("%ld",&i); 
	bonus1=100000*0.1;
	bonus2=bonus1+100000*0.075; 
	bonus4=bonus2+200000*0.05; 
	bonus6=bonus4+200000*0.03; 
	bonus10=bonus6+400000*0.015; 
	if(i<=100000) 
		bonus=i*0.1; 
	else if(i<=200000) 
		bonus=bonus1+(i-100000)*0.075; 
	else if(i<=400000) 
		bonus=bonus2+(i-200000)*0.05; 
	else if(i<=600000) 
		bonus=bonus4+(i-400000)*0.03; 
	else if(i<=1000000) 
		bonus=bonus6+(i-600000)*0.015; 
	else 
		bonus=bonus10+(i-1000000)*0.01; 
	printf("bonus=%d",bonus); 
	return 0;
} 

