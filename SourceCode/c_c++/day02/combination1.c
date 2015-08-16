/*************************************************************************
    > File Name: combination1.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月03日 星期一 22时05分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main() {
	int i, j, k;
	printf("\n");
	for (i = 1; i < 5; i++)
		for (j = 1; j < 5; j++)
			for (k = 1; k < 5; k++)
				if (k != j && k != i && j != i)
					printf("%d  ", i * 100 + j * 10 + k);
}
