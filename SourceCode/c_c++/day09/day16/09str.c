/*
    字符串函数演示
*/
#include <stdio.h>
int main() {
    int num = 0;
    float fnum = 0.0f;
    char ch = 0;
    char buf[20] = {};
    //printf("请输入数字：");
    //scanf("%c%d%g", &ch, &num, &fnum);
    sscanf("x 39 8.54", "%c%d%g", &ch, &num, &fnum);
    //printf("%g %d %c\n", fnum, num, ch);
    sprintf(buf, "%g %d %c\n", fnum, num, ch);
    printf("%s", buf);
    return 0;
}



