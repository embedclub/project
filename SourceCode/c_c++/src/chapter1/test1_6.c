/*
6����д��׼���е����ݺ�����int power(int x, int y)��
*/

#include <stdio.h>
int power(int x, int y)
{
	int i, p=1;
	
	for (i = 1; i <= y; ++i)
		p = p * x;
	return p;	
}

main()
{
	printf("power(3,2) is %d\n", power(3,2));
}
