/*
    文件操作程序框架
*/
#include <stdio.h>
int main() {
    FILE *p_file = fopen("a.txt", "w");//没有的话，会自动创建a.txt
    /*if (p_file) {
        //
        fclose(p_file);
        p_file = NULL;
    }*/
    if (!p_file) {
        return 0;
    }
    fclose(p_file);
    p_file = NULL;
    return 0;
}



