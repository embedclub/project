/*
3����дһ�������븴�Ƶ�����ĳ���
�������������Ķ���ո���һ���ո���档
*/

#include <stdio.h>

#define NOBLANK 'a'

/* replace string of blanks with a single blank */

int main()
{
	int c, lastc;

	lastc = NOBLANK;
	while ((c = getchar()) != EOF) {
		if ( c != ' ' || lastc != ' ')
			putchar(c);
		lastc = c;
	}
	return 0;
}

