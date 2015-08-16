/*************************************************************************
    > File Name: date.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月04日 星期二 09时40分41秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main() {
	int year, month, day, sum;
	printf("请输入年月日：");
	scanf("%d%d%d", &year, &month, &day);
	switch (month) {
		case 1:sum = 0;break;
		case 2:sum = 31;break;
		case 3:sum = 59;break;
		case 4:sum = 90;break;
		case 5:sum = 120;break;
		case 6:sum = 151;break;
		case 7:sum = 181;break;
		case 8:sum = 212;break;
		case 9:sum = 243;break;
		case 10:sum = 273;break;
		case 11:sum = 304;break;
		case 12:sum = 334;break;
		default:printf("error!\n");break;
	}
	if (month < 3) {
		sum = sum + day;
	} else {
		sum = sum + day;
		if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			sum = sum + 1;//此处逻辑有问题，数字被计算两边
		}
	}
	printf("sum = %d\n", sum);
		
}
