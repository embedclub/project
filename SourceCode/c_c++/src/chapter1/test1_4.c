/*
4、编写一个程序，统计输入的行数、单词数与字符数。
*/

#include <stdio.h>

#define IN 1
#define OUT 0

/*count newlines, words, and characters*/

int main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc =0;
	while ((c = getchar()) !=EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\t' || c == '\n')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("the number of newlines is : %d\n",nl);
	printf("the number of words is : %d\n",nw);
	printf("the number of characters is : %d\n",nc);
	return 0;
}
