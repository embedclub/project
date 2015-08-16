/*************************************************************************
    > File Name: comparsion.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月04日 星期二 22时58分36秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int max(int, int, int);//函数声明
int main(void) {
	int x, y, z;//输入参数的变量名
	int temp;//临时仓库的作用
	printf("请输入三个数字：");
	scanf("%d%d%d", &x, &y, &z);
	if (x < y) {
		temp = x;
		x = y;
		y = temp;
	}
	if(x < z) {
		temp = x;
		x = z;
		z = temp;
	} 
	if (y < z) {
		temp = y;
		y = z;
		z = temp;
	}
	temp = max(11233,234,355);
	printf("max = %d\n", temp);
	printf("从小到大的排列是：%d %d %d\n", z, y, x);
	return 0;
}

int max(int x, int y, int z) {
	int result;
	result = (x < ((y < z)?z:y) ? ((y < z)?z:y) : x);
	return result;
}
