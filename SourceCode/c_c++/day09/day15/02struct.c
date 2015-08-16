/*
    数据对齐和补齐演示
*/
#include <stdio.h>
typedef struct {
    char buf[2];
    int num;
} stru;
typedef struct {
    char ch;
    int num;
    char ch1;
} stru1;
int main() {
    printf("sizeof(stru)是%d\n", sizeof(stru));
    printf("sizeof(stru1)是%d\n", sizeof(stru1));
    return 0;
}
