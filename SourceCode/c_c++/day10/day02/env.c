#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{	
	extern char **environ;
	//char *str = "abc";
	//printf("%s\n", str);
	char **p = environ;
	while(*p)
	{
		printf("%s\n", *p);
	    p++;
		//*(p++);
		//(*p)++; //错误
	}
	char value[100] = {0};
	//取出字符串 "SHELL=/bin/bash"  =后的/bin/bash
	//字串存入value ,并且打印
    p = environ;
	while(*p)
	{
			/*SHELL=/bin/bashi  p *p*/
		if(strncmp(*p , "SHELL=", 6) == 0)
		{
			strcpy(value, *p+6);
			printf("value = %s\n", value);
			break;
		}
		p++;//移动指针指向下一个字符串
	}	
	return 0;
}




