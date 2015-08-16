/*************************************************************************
    > File Name: grap.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月04日 星期二 23时30分07秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main() { 
	char a=176,b=219; 
	printf("%c%c%c%c%c\n",b,a,a,a,b); 
	printf("%c%c%c%c%c\n",a,b,a,b,a); 
	printf("%c%c%c%c%c\n",a,a,b,a,a); 
	printf("%c%c%c%c%c\n",a,b,a,b,a); 
	printf("%c%c%c%c%c\n",b,a,a,a,b);
} 

