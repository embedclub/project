/*
    布雷练习
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int map[10][10] = {}, row = 0, col = 0, num = 0;
    srand(time(0));
    //布置10个地雷
    do {
        row = rand() % 10;
        col = rand() % 10;
        if (!map[row][col]) {
            map[row][col] = 1;
            num++;
        }
    } while (num < 10);
    //打印地图
    for (row = 0;row <= 9;row++) {
        for (col = 0;col <= 9;col++) {
            printf("%d", map[row][col]);
        }
        printf("\n");
    }
    return 0;
}


