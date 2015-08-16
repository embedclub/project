/*************************************************************************
    > File Name: 07test.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月07日 星期五 20时50分17秒
    > Version: 1.0  
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

void printb(int x, int n);
int main(void) {
	int x;
	printf("Input number:");
	scanf("%d", &x);
	printf("number of decimal form: %d\n", x);
	printf("	it's binary form:");
	printb(x, sizeof(int) * 8);
	putchar('\n');
}

void printb(int x, int n) {
	if (n > 0) {
		putchar('0' + ((unsigned)(x & (1 << (n - 1))) >> (n - 1)) );
		printb(x, n - 1);
	}
}
