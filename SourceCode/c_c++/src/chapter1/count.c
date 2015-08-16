#include <stdio.h>

main()
{
	char c;
        int a=0,b=0,d=0;
	while ((c = getchar()) != EOF)
       {
        switch(c)
         {
          case  ' ':  a++;break;
          case '\t':  b++;break;
          case '\n':  d++;break;
          default: break;
         }
       }
      printf("' ' is  %d\n'\\t' is %d\n'\\n' is %d\n ",a,b,d);

}
