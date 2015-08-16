/*
    打地鼠游戏练习
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int hamx = 0 /*锤子的列号*/, hamy = 0 /*锤子的行号*/,mousex = 0 /*老鼠的列号*/, mousey = 0 /*老鼠的行号*/, hits = 0 /*打中的次数*/, missed = 0 /*错过的次数*/, times = 0 /*要玩多少次*/, curr = 0/*每次的编号*/, row = 0, col = 0;
    srand(time(0));
    printf("请输入次数：");
    scanf("%d", &times);
    printf("***\n***\n***\n");
    for (curr = 1;curr <= times;curr++) {
        //每循环一次就打一次
        //用循环保证获得一个有效的锤子位置
        do {
            printf("请输入锤子的位置：");
            scanf("%d%d", &hamy, &hamx);
        } while (hamx < 1 || hamx > 3 || hamy < 1 || hamy > 3);
        //获得老鼠位置
        mousex = rand() % 3 + 1; 
        mousey = rand() % 3 + 1;
        //使用循环嵌套打印地图
        for (row = 1;row <= 3;row++) {
            for (col = 1;col <= 3;col++) {
                if (row == hamy && col == hamx) {
                    printf("O");
                }
                else if (row == mousey && col == mousex) {
                    printf("X");
                }
                else {
                    printf("*");
                }
            }
            printf("\n");
        }
        if (hamx == mousex && hamy == mousey) {
            //如果打中的处理语句
            hits++;
            printf("打中了\n");
        }
        else {
            //如果没有打中的处理语句
            missed++;
            printf("没打中\n");
        }
        printf("共打中%d次，错过%d次\n", hits, missed);
    }
    return 0;
}





