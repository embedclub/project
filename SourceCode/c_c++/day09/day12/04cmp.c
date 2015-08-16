/*
    字符串函数演示
*/
#include <stdio.h>
#include <string.h>
int main() {
    char str[20] = {};
    printf("比较结果是%d\n", strcmp("abc", "abd"));
    printf("%s\n", strcpy(str, "abcxyz"));
    printf("%s\n", str);
    return 0;
}
