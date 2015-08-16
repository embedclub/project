/*
    打地鼠练习
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int times = 0/*记录次数*/, hamy = 0/*锤子的垂直位置*/, hamx = 0/*锤子的水平位置*/, mousey = 0/*老鼠的垂直位置*/, mousex = 0/*老鼠的水平位置*/, hits = 0/*打中次数*/, missed = 0/*错过次数*/, row = 0/*外循环变量*/, col = 0/*内循环变量*/;
    srand(time(0));
    printf("请输入次数：");
    scanf("%d", &times);
    //循环用户指定的次数
    for (;times >= 1;times--) {
        //获得锤子位置
        printf("请输入锤子的位置：");
        scanf("%d%d", &hamy, &hamx);
        //获得老鼠位置
        mousey = rand() % 3 + 1;
        mousex = rand() % 3 + 1;
        //调整打中和错过次数
        if (hamy == mousey && hamx == mousex) {
            //如果锤子和老鼠位置重叠就说明打中了
            hits++;
        }
        else {
            //如果不重叠就说明错过了
            missed++;
        }
        //打印鼠洞
        for (row = 1;row <= 3;row++) {
            for (col = 1;col <= 3;col++) {
                if (hamy == row && hamx == col) {
                    //打印锤子
                    printf("O");
                }
                else if (mousey == row && mousex == col) {
                    //打印老鼠
                    printf("X");
                }
                else {
                    //打印空位置
                    printf("*");
                }
            }
            printf("\n");
        }
        printf("打中%d次，错过%d次\n", hits, missed);
    }
    return 0;
}



