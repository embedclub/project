/*
    获取字符串演示
*/
#include <stdio.h>
#include <string.h>
int main() {
    char str[10] = {};
    printf("请输入一个字符串：");
    fgets(str, 10, stdin);
    printf("字符串是%s\n", str);
    if (strlen(str) ==  9 && str[8] != '\n') {
        scanf("%*[^\n]");
        scanf("%*c");
    }
    printf("请输入一个字符串：");
    fgets(str, 10, stdin);
    printf("字符串是%s\n", str);
    return 0;
}
