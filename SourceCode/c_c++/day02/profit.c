/*************************************************************************
    > File Name: profit.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月03日 星期一 22时28分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void) {
	long int profit; 
	int bonus;
	printf("请输入当月的利润：");
	scanf("%ld", &profit);
	if(profit <= 100000) {
		bonus = profit * 0.1;
	} else if (profit <= 200000) {
		bonus = (profit - 100000) * 0.075 + 100000 * 0.1;
	} else if (profit <= 400000) {
		bonus = (profit - 200000) * 0.05 + 100000 * 0.075 + 100000 * 0.1;
	} else if (profit <= 600000) {
		bonus = (profit - 400000) * 0.03 + 200000 * 0.05 + 100000 * 0.175;
	} else if (profit <= 1000000) {
		bonus = (profit - 200000) * 0.015 + 200000 * 0.03 + 100000 * 0.275;
	} else {
		bonus = (profit - 1000000) * 0.01 + 100000 * 0.335 + 400000 * 0.015;
	}
	printf("bonus = %d\n", bonus);
}
