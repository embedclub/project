/*
    标准函数演示
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int num = atoi("347");
    double dnum = 0.0;
    printf("num是%d\n", num);
    dnum = atof("34.98");
    printf("dnum是%lg\n", dnum);
    printf("36的平方根是%lg\n", sqrt(36));
    printf("2的3次方是%lg\n", pow(2, 3));
    return 0;
}




