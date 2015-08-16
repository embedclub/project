/*************************************************************************
    > File Name: main.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月15日 星期六 23时14分18秒
    > Version: 1.0  
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

void char_info(void);
int Dec_Bin(int num);
int Dec_bin2(int num);
void Binaty(void);
void opr_display(void);

int main(void) {
	char_info();
	Dec_Bin(4);
	return 0;
}

void char_info(void) {
/*
 *     特殊字符演示
 *     */
	    printf("abcde\n");
		printf("abc\rde\n");
		printf("abc\tde\n");
		printf("ab\tde\n");
/*
*     占位符使用演示
*     */
		printf("%d\n", 7);
		printf("%3d\n", 7);
		printf("%-3dabc\n", 7);
		printf("%03d\n", 7);
		printf("%7.2f\n", 3.7f);
/*
 *     sizeof关键字演示
 *     */
		short snum = 0;
		printf("sizeof(int)是%d,sizeof(snum)是%d\n", sizeof(int), sizeof(snum));
		printf("sizeof(3 + 7)是%d\n", sizeof(3 + 7));
		sizeof(snum = 10);
		printf("snum是%hd\n", snum);
/*
 *     进制演示
 *     */
		printf("%d 0%o\n", 0156, 0156);
		printf("%d 0x%x 0X%X\n", 0x6e, 0x6e, 0x6e);
}
/*
 *      二进制练习
 *      */
int Dec_Bin(int num) {
	    printf("%8d\r", num % 2);
		num = num / 2;
		printf("%7d\r", num % 2);
		num = num / 2;
		printf("%6d\r", num % 2);
		num = num / 2;
		printf("%5d\r", num % 2);
		num = num / 2;
		printf("%4d\r", num % 2);
		num = num / 2;
		printf("%3d\r", num % 2);
		num = num / 2;
		printf("%2d\r", num % 2);
		num = num / 2;
		printf("%d\n", num % 2);
		return 0;
}
/*
 *     二进制作业
 *     */
int Dec_bin2(int num) {

	    int base = 128;
		printf("%d", num / base);
		num = num % base;
		base = base / 2;
		printf("%d", num / base);
		num = num % base;
		base = base / 2;
		printf("%d", num / base);
		num = num % base;
		base = base / 2;
		printf("%d", num / base);
		num = num % base;
		base = base / 2;
		printf("%d", num / base);
		num = num % base;
		base = base / 2;
		printf("%d", num / base);													num = num % base;
		base = base / 2;
		printf("%d", num / base);
		num = num % base;
		base = base / 2;
		printf("%d\n", num / base);
																					return 0;
}
/*
 *     二进制用处演示
 *     */
void Binaty(void) {
	    char ch = 300;
		int num = 0;
		printf("%hhd\n", ch);
		ch = 200;
		printf("%hhd\n", ch);
		num = ch;
		printf("%d\n", num);
		printf("&num是%p\n", &num);
}

/*
 *     操作符演示
 *     */
void opr_display(void) {

	    int num = 0;
		char ch = 0;
		num = (2 + 3, 7 + 4);
		printf("num是%d\n", num);
		printf("(ch = 300)是%d\n", (ch = 300));
		num = ch = 200;
		printf("num是%d,ch是%d\n", num, ch);
		num = 10;
		num *= 2 + 3;
		printf("num是%d\n", num);
}

