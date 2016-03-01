
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *str1 = "abcd";
	char str2[] = "abcd";
	char *str3 = "abcd";

	//str1++;
	//(*str1)++;//段错误
	//str2++;//错误
	(*str2)++;
	
	char *test = NULL;
	test = malloc(10);
	strcpy(test, "hello");
	
	//strcmp(str1, str2)	
	if(str1 == str2)
	{
		printf("str1 = str2\n");
	}
	else
	{
		printf("str1 != str2\n");
	}
	if(str1 == str3)
	{
		printf("str1 = str3\n");
	}
	else
	{
		printf("str1 != str3\n");
	}
	
	


}
