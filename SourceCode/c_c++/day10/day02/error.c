
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int random10(void)
{
	srand(time(0));
	int r = rand()%10;
	if(r == 5)
	{
		return -1;
	}
	return r;
}
int max(int x, int y, int *res)
{
	if(x == y)
	{
		return -1;
	}
	*res = x>y?x:y;
	return 0;
}
char *str_cmp(char *s)
{
	if(!strcmp(s, "error"))
	{	
		return NULL;
	}
	return s;
}
void print(char *str)
{
	printf("\n");
	printf("%s\n", str);
}
int main(void)
{
	int r = 0;
	if(max(3,4,&r) == -1)
	{
		printf("max failed!\n");
	}
	
	r = random10();
	if(r == -1)
	{
		printf("random failed!\n");
	}

	if(str_cmp("error") == NULL)
	{
		printf("str_cmp failed!\n");
	}
	print("hello");

	return 0;
}





