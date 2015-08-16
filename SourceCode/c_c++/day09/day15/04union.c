/*
    联合演示
*/
#include <stdio.h>
struct stru {
    char buf[2];
    int num;
};
union un {
    char buf[2];
    int num;
};
int main() {
    union un un1;
    printf("un1.buf是%p,&(un1.num)是%p\n", un1.buf, &(un1.num));
    printf("sizeof(union un)是%d\n", sizeof(union un));
    return 0;
}



