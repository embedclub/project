/*************************************************************************
    > File Name: stairs.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月05日 星期三 12时20分52秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void) {
	int i,j; 
	printf("\1\1\n");/*输出两个笑脸*/ 
	for(i=1;i<11;i++) { 
		for(j=1;j<=i;j++) 
		printf("%c%c",219,219); 
		printf("\n"); 
	} 
	
	return 0;
}
