/*
2����дһ��ͳ�ƿո��Ʊ���뻻�з������ĳ���
*/
/* count blanks, tabs, and newlines*/
#include <stdio.h>

int main()
{
	int c, nb, nt, nl;
	nb = 0;
	nt = 0;
	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == ' ')
			++nb;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nl;
	printf("\nthe blans number is: %d\n",nb);

	printf("\nthe tabs number is: %d\n",nt);
	printf("\nthe newlines number is: %d\n",nl);
	return 0;
}
