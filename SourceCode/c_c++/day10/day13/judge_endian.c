#include <stdio.h>
#include <stdlib.h>

int main()
{
	union
	{
		int a;
		char c;
	}test;
	test.a = 1;
	if(test.c == 1)
	{
		printf("这台机器使用的是小端模式\n");
	}
	else
	{
		printf("这台机器使用的是大端模式\n");
	}
}
