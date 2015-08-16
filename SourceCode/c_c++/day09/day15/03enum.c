/*
    枚举类型演示
*/
#include <stdio.h>
int main() {
    enum gender {NAN = 3, NV};
    printf("NAN是%d\n", NAN);
    printf("NV是%d\n", NV);
    enum gender gen1 = NAN;
    return 0;
}
