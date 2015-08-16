/*************************************************************************
    > File Name: combination.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月03日 星期一 21时52分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void) {
	int i, j, k, t, m;
	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= 4; j++) {
			for (k = 1; k <= 4; k++) {
				for (t =1; t <= 4; t++) {
					if (t == k || t == j || t == i || k == j || k == i || j == i) continue;
					else {
						m = i * 1000 + j * 100 + k * 10 + t;
						printf("result = %d ", m);
					}
					printf("\n");
				}
			}
		}
	}
}
