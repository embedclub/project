/*
    指针类型返回值演示
*/
#include <stdio.h>
/*int *read() {
    int num = 0;
    printf("请输入一个数字：");
    scanf("%d", &num);
    return &num;
}*/
int *read(int *p_num) {
    printf("请输入一个数字：");
    scanf("%d", p_num);
    return p_num;
}
int main() {
    int num = 0;
    int *p_num = read(&num);
    printf("数字是%d\n", *p_num);
    return 0;
}
