/*************************************************************************
    > File Name: 08test.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月07日 星期五 21时16分43秒
    > Version: 1.0  
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void) {
	int i;
	for (i = 0; i <= 300; i += 20) 
		printf("%-3d  %-3d\n", i, (int)((5.0 / 9.0) * (i - 32)));
}
