/*
    文件练习
*/
#include <stdio.h>
int main() {
    int id = 0;
    char name[10] = {};
    float salary = 0.0f;
    FILE *p_file = fopen("person.bin", "rb");
    if (p_file) {
        while (fread(&id, sizeof(int), 1, p_file)) {
            fread(name, sizeof(char), 10, p_file);
            fread(&salary, sizeof(float), 1, p_file);
            printf("id是%d，姓名是%s,工资是%g\n", id, name, salary);
        }
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
