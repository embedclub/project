/*
    主函数参数
	实际上main函数是有三个参数的envp
*/
#include <stdio.h>
int main(int argc, char **argv) {
    int num = 0;
    for (num = 0;num <= argc - 1;num++) {
        printf("%s\n", *(argv + num));
    }
    return 0;
}
