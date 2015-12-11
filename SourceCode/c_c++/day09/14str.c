/*
    字符串演示
*/
#include <stdio.h>
int main() {
    printf("%p\n", "abc");
    printf("%p\n", "abc");
    printf("%p\n", "abc");
    printf("%p\n", "ab""c");
    printf("%c\n", *("abc"));
    printf("%hhd\n", *("abc" + 0));
    //*("abc") = 'x';    错误
    return 0;
}
