/*
    动态分配内存练习
*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    int id = 0;
    char *p_ch = (char*)malloc(10 * sizeof(char)); 
    if (!p_ch) {
        return 0;
    }
    FILE *p_file = fopen("person.bin", "rb");
    if (p_file) {
        while (fread(&id, sizeof(int), 1, p_file)) {
            fread(p_ch, sizeof(char), 10, p_file);
            printf("姓名是%s\n", p_ch);
            fseek(p_file, 4, SEEK_CUR);
        }
        fclose(p_file);
        p_file = NULL;
    }
    free(p_ch);
    p_ch = NULL;
    return 0;
}
