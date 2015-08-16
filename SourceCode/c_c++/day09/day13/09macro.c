/*
    宏演示
*/
#include <stdio.h>
#define   SQUARE(x)     ((x) * (x))
int main() {
    int num = 5;
    printf("SQUARE(6)是%d\n", SQUARE(6)); 
    printf("SQUARE(++num)是%d\n", SQUARE(++num));
    return 0;
}
