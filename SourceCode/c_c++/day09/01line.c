/*
    结构体作业
*/
#include <stdio.h>
typedef struct {
    int x, y;
} pt;
typedef struct {
    pt pt1, pt2;
} line;
//计算线段长度平方的宏
#define   LEN2(line)  (((line)->pt1.x - (line)->pt2.x) * ((line)->pt1.x - (line)->pt2.x) + ((line)->pt1.y - (line)->pt2.y) * ((line)->pt1.y - (line)->pt2.y))
//获得线段位置
line *read(line *p_line) {
    printf("请输入线段位置：");
    scanf("%d%d%d%d", &(p_line->pt1.y), &(p_line->pt1.x), &(p_line->pt2.y), &(p_line->pt2.x));
    return p_line;
}
//查找比较长的线段
const line *longer_line(const line *p_line1, const line *p_line2) {
    return LEN2(p_line1) > LEN2(p_line2) ? p_line1 : p_line2;
}
//打印线段位置
void print(const line *p_line) {
    printf("线段位置是((%d, %d), (%d, %d))\n", p_line->pt1.y, p_line->pt1.x, p_line->pt2.y, p_line->pt2.x);
}
int main() {
    line line1 = {}, line2 = {};
    const line *p_line = NULL;
    read(&line1);
    read(&line2);
    p_line = longer_line(&line1, &line2);
    print(p_line);
    return 0;
}





