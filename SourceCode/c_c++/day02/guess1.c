/*************************************************************************
    > File Name: guess1.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月04日 星期二 09时24分32秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include "math.h" 
int main() { 
	long int i,x,y,z; 
	for (i=1;i<100000;i++) { 
		x=sqrt(i+100); /*x为加上100后开方后的结果*/ 
		y=sqrt(i+168); /*y为再加上168后开方后的结果*/ 
		if(x*x==i+100&&y*y==i+168)/*如果一个数的平方根的平方等于该数，这说明此数是完全平方数*/ 
		printf("\n%ld\n",i); 
	}
	return 0; 
} 

