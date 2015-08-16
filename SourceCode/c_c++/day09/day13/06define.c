/*
    define预处理指令演示
*/
#include <stdio.h>
#define    PI             3.14f
#define    CIRCLE(r)      2 * PI * r
#define    AREA(r)        PI * r * r
int main() {
    int radius = 0;
    printf("请输入圆的半径：");
    scanf("%d", &radius);
    printf("圆的周长是%g\n", CIRCLE(radius));
    printf("圆的面积是%g\n", AREA(radius));
    return 0;
}




