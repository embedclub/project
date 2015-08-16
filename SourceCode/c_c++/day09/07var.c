/*
    生命周期和作用域演示
*/
#include <stdio.h>
int val;
void func(void) {
    int num1 = 0;
    {
        int num2 = 0;
        printf("num1是%d\n", num1);
        printf("num2是%d\n", num2);
    }
    printf("num1是%d\n", num1);    
    //printf("num2是%d\n", num2);
    //printf("num是%d\n", num);   变量名不可以使用
    printf("val是%d\n", val);
}
int main() {
    int num = 0;
    func();
    printf("num是%d\n", num);
    //printf("num1是%d\n", num1);    错误
    //printf("num2是%d\n", num2);
    printf("val是%d\n", val);
    return 0;
}
