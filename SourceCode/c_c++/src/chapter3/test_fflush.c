/*test fflush*/

#include <stdio.h>
#include <string.h>
//#include <stdlib.h>




main()
{
//	unsigned x;
	
	int n,x,y,m;
	char c;
	char s[20];
/*
	gets(s);
	printf(" Input int n :\n");
	printf(" Input int x :\n");
	
	scanf("%d", &x);
	fflush(stdin);

	//printf(" Input int x :\n");
	
	scanf("%d", &y);
	scanf("%d", &m);
	scanf("%d", &n);
	

	printf(" Output  x= %d\n", x);
	printf(" Output  y= %d\n", y);
	printf(" Output  m= %d\n", m);
	printf(" Output  n= %d\n", n);
	
	printf("%s\n",s); */

	 for(;;) {
	 	scanf("%d", &x);
	 	while ((c = getchar() )!=EOF);
		printf("%d\n", x);
		//fflush(stdin);
	 }
		
 	

}

