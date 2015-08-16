/*************************************************************************
    > File Name: chess.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月05日 星期三 12时00分43秒
1.程序分析：用i控制行，j来控制列，根据i+j的和的变化来控制输出黑方格，还是白方格。
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void) {
	int i,j; 
	for(i=0;i<8;i++) { 
		for(j=0;j<8;j++) 
		if((i+j)%2==0) 
			printf("%c%c",219,219); 
		else 
			printf("  "); 
		printf("\n"); 
	} 
	return 0;
}
