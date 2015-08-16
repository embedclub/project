#include <stdio.h>
#pragma pack(1)

struct s1
{
	char a; //1
	int b;  //4
	char c; //1
	short e;//2
	double d;//8
};
int main()
{
	printf("double size = %d\n", sizeof(double));
	printf("struct s1 size = %d\n",
			sizeof(struct s1));
	return 0;
}






