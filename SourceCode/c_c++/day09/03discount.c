/*
    条件编译演示
*/
#include <stdio.h>
int main() {
#if   defined(ELITE)
    printf("120%%\n");
#elif  !defined(ELITE) && !defined(FACTORY)
    printf("100%%\n");
#else
    printf("80%%\n");
#endif
    return 0;
}
