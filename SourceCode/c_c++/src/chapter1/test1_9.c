/*
9����дһ��ɾ��C���Գ��������е�ע�� ��䡢
Ҫ��ȷ��������ŵ��ַ������ַ�������
*/

#include <stdio.h>

void rcomment(int c);
void in_comment1(void);
void in_comment2(void);
void print_quote(int c);    

main()
{
	int c, d;
	while ((c = getchar()) != EOF)   
		rcomment(c);
	return 0;
}

void rcomment(int c)
{
	int d;
	if (c == '/')
		if ((d = getchar()) == '*')
			in_comment1();
		else if (d = '/') {
			in_comment2();
		} else {
			putchar(c);
			putchar(d);
		}
	else if (c == '\'' || c == '"')
		print_quote(c);
	else
		putchar(c);
}

void in_comment1(void)
{
	int c, d;
	c = getchar();
	d = getchar();
	while (c != '*' || d != '/') {
		c = d;
		d = getchar();
	}
}

void in_comment2(void)
{
	int c;
	c = getchar();
	while ( c != '\n')
		c = getchar();		
}

void print_quote(int c)
{
	int d;
	putchar(c);
	while ((d = getchar()) != c) {
		putchar(d);
		if (d = '\\')
			putchar(getchar()); //���������ӷ�"\"
	}
	putchar(d);
}
