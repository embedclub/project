/*
    模拟登陆练习
*/
#include <stdio.h>
#include <string.h>
int main() {
    char buf[10] = {};
    int num = 0;
    for (num = 1;num <= 3;num++) {
        printf("请输入用户名：");
        fgets(buf, 10, stdin);
        if (strlen(buf) == 9 && buf[8] != '\n') {
            scanf("%*[^\n]");
            scanf("%*c");
			printf("helo\n");
        }
        if (strcmp(buf, "admin\n")) {
			printf("bad\n");
            continue;
        }
        printf("请输入密码：");
        fgets(buf, 10, stdin);
        if (strlen(buf) == 9 && buf[8] != '\n') {
            scanf("%*[^\n]");
            scanf("%*c");
        }
        if (strcmp(buf, "123456\n")) {
            continue;
        }
        break;
    }
    if (num <= 3) {
        printf("登陆成功\n");
    }
    else {
        printf("登陆失败\n");
    }
    return 0;
}




