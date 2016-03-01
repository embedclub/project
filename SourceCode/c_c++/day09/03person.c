/*
    人员信息管理系统
*/
#include <stdio.h>
#include <string.h>
int main() {
    int id = 0, oldid = 0, choice = 1;
    char name[10] = {};
    float salary = 0.0f;
    FILE *p_file = fopen("person.bin", "a+b");
    if (p_file) {
        do {
            printf("请输入id:");
            scanf("%d", &id);
            scanf("%*[^\n]");
            scanf("%*c");
            oldid = -1;
            rewind(p_file);
            while (fread(&oldid, sizeof(int), 1, p_file)) {
                if (id == oldid) {
                    break;
                }
                fseek(p_file, 14, SEEK_CUR);
            }
            fseek(p_file, 0, SEEK_END);
            if (id == oldid) {
                continue;
            }
            printf("请输入姓名：");
            fgets(name, 10, stdin);
            if (strlen(name) == 9 && name[8] != '\n') {
                scanf("%*[^\n]");
                scanf("%*c");
            }
            printf("请输入工资：");
            scanf("%g", &salary);
            fwrite(&id, sizeof(int), 1, p_file);
            fwrite(name, sizeof(char), 10, p_file);
            fwrite(&salary, sizeof(float), 1, p_file);
            printf("是否需要输入下一个人员信息？0表示不需要，1表示需要");
            scanf("%d", &choice);
        } while (choice);
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
