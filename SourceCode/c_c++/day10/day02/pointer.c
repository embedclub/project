

#include <stdio.h>

int main()
{
	char *p = "abcde";
	printf("p = %p\n", p);
	p++;
	printf("p+1 = %p\n", p);

	int arr;
	int *pi = &arr;
	printf("pi = %p\n", pi);
	pi++;
	printf("pi+1 = %p\n", pi);


    return 0;
}

