/*
    字符串函数演示
*/
#include <stdio.h>
#include <string.h>
int main() {
    char str[20] = "abc";
    printf("有效字符个数是%d\n", strlen("abcde"));
    printf("%s\n", strcat(str, "xyz"));
    printf("%s\n", str);
    return 0;
}
