/*************************************************************************
    > File Name: 05test.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月07日 星期五 19时40分40秒
    > Version: 1.0  
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void) {
	int a, b, c, count = 0;
	printf("There are different methods for XM to distribute books to 3 readers:\n");
	for (a = 1; a <= 5; a++)
		for (b = 1; b <= 5; b++)
			for (c = 1; a != b && c <= 5; c++)
				if (c != a && c != b)
					printf(count % 8 ? "%2d:%d,%d,%d  " : "%2d:%d,%d,%d  \n", ++count, a, b, c);
	return 0;
}
