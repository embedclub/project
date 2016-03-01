/*************************************************************************
    > File Name: test.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年12月17日 星期四 10时55分20秒
    > Version: 1.0  
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main() {
	int id = 0, oldid = 0, choice = 1;
	char name[10] = {};
	float salary = 0.0f;
	FILE *fp = fopen("b.txt", "a+b");
	if (fp) {
		do {
			printf("请输入id：");
			scanf("%d", &id);
			scanf("%*[^\n]");
			scanf("%*c");
			oldid = -1;
			rewind(fp);
			while (fread(&oldid, sizeof(int), 1, fp)) {
				if (id == oldid) {
					break;
				}
				fseek(fp, 14, SEEK_CUR);
			}
			fseek(fp, 0, SEEK_END);
			if (id == oldid) {
				continue;
			}
			printf("请输入姓名：");
			fgets(name, 10, stdin);
			if(strlen(name) == 9 && name[8] != '\n') {
				scanf("%*[^\n]");
				scanf("%*c");
			}
			printf("请输入工资：");
			scanf("%g", &salary);
			fwrite(&id, sizeof(int), 1, fp);
			fwrite(name, sizeof(char), 10, fp);
			fwrite(&salary, sizeof(float), 1, fp);
			printf("go on?1--yes,0--No");
			scanf("%d", &choice);
		} while(choice);
		fclose(fp);
		fp = NULL;
	}
	return 0;
}
