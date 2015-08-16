/*************************************************************************
    > File Name: arcos.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月02日 星期日 19时53分32秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#include<time.h>
#include<unistd.h>

int main(void) {
	double y;
	int m;
	y = 1;
	while (y >= -1) {
		m = acos(y) * 100;
		y -= 0.1;
		printf("m = %d\n", m);
//		sleep(1);

	}
}
