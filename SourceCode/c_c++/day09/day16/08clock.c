/*
    秒表练习
*/
#include <stdio.h>
#include <unistd.h>
int main() {
    int sec = 0;
    while (1) {
        printf("%5d\r", sec);
        fflush(stdout);
        sec++;
        sleep(1);
    }
    return 0;
}
