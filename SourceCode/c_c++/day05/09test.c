/*************************************************************************
    > File Name: 09test.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月07日 星期五 21时28分47秒
    > Version: 1.0 
	> 功能： 用于统计空格、制表符和换行符的个数
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main() {
	int c, nb, nt, nl;
	nb = 0;
	nt = 0;
	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == ' ')
			++nb;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nl;
	printf("\nthe blans number is: %d\n", nb);
	printf("\nthe tabs number is: %d\n", nt);
	printf("\nthe newlines number is: %d\n", nl);
	return 0;
}

