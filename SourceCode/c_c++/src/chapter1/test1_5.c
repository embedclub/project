/*
5����дһ������ͳ�Ƹ������֡�
�հ׷��������ո�����Ʊ�������з���,
�Լ����������ַ����ֵĴ�����
*/

#include <stdio.h>

/* count the number of digital, blanks, and characters */

main()
{
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;
	
	while ((c = getchar()) != EOF)
		if (c >= '0' && c <='9')
			++ndigit[c-'0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	
	printf("digits = ");
	for (i = 0; i < 10; ++i)
		printf("the number  %d count is: %d\n",i, ndigit[i]);
	printf("white space = %d, other = %d\n",nwhite, nother);
}
