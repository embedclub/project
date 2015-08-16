/*************************************************************************
    > File Name: 01test.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月08日 星期六 17时03分14秒
    > Version: 1.0  
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
struct date {
	int year;
	int month;
	int day;
};

long int days(struct date day);

int main(void) {
	struct date today, term;
	int yearday, year, day; 
	printf("Enter year/month/day:");
	scanf("%d%d%d", &today.year, &today.month, &today.day);  /* 输入日期 */
	term.month = 12;					/* 设置变量的初始值： 月*/
	term.day = 31;						/* 设置变量的初始值： 日*/
	for (yearday = 0, year = 1990; year < today.year; year++) {
		term.year = year;
		yearday += days(term); /* 计算从1990年至指定年的前一年共有多少天 */
	}
	yearday += days(today);		/* 加上指定年中到指定日期的天数 */
	day = yearday % 5;							/*	求余数 */
	if (day > 0 && day < 4)
		printf("He was fishing at that day.\n");/* 打印结果 */
	else
		printf("He was sleeping at that day.\n");
	return 0;
}

long int days(struct date day) {
	static int day_tab[2][13] = 
	{{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};
	int i, leap;
	leap = day.year % 4 == 0 && day.year % 100 != 0 || day.year % 400 == 0;
	for (i = 1; i < day.month; i++)
		day.day += day_tab[leap][i];
	return(day.day);
}
