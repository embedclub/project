/*
    touch命令作业
*/
#include <stdio.h>
int main(int argc, char **argv) {
    FILE *p_file = fopen(*(argv + 1), "a");
    if (p_file) {
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
