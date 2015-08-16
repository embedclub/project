/*************************************************************************
    > File Name: main.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2015年08月16日 星期日 10时05分17秒
    > Version: 1.0  
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
void char_info(void);
int Dec_Bin(int num);
int Dec_bin2(int num);
void Binaty(void);
void opr_display(void);
int leap(int year);
int three_choice(int num);
int keyword_use1();
int Dec_Bin3(int num);
int compute_day(int year, int month);
int keyword_use2();
int display_char();
void type_display();
int arr_bin();
int use_rand();
int string_display();
int arr1toarr2();
int arr2_exercise();
int arrary2();
int lottery();
int su(int num);

/*
    颠倒数组作业
*/

void reverse(int arr[], int size) {
    int pre = 0, post = size - 1;
    while (pre < post) {
        //交换配对存储区的内容
        int tmp = arr[pre];
        arr[pre] = arr[post];
        arr[post] = tmp;
        //调整配对存储区的位置
        pre++;
        post--;
    }
}

int main(void) {
	char_info();
	Dec_Bin(4);
	Dec_bin2(7);
	Binaty();
	opr_display();
	int i = leap(2015);
	int j = three_choice(-100);
	keyword_use1();
    Dec_Bin3(7);
	compute_day(2014, 2);
	keyword_use2();
	display_char();
	type_display();
	arr_bin();
	use_rand();
	return 0;
}

void char_info(void) {
/*
 *     特殊字符演示
 *     */
	    printf("abcde\n");
		printf("abc\rde\n");
		printf("abc\tde\n");
		printf("ab\tde\n");
/*
*     占位符使用演示
*     */
		printf("%d\n", 7);
		printf("%3d\n", 7);
		printf("%-3dabc\n", 7);
		printf("%03d\n", 7);
		printf("%7.2f\n", 3.7f);
/*
 *     sizeof关键字演示
 *     */
		short snum = 0;
		printf("sizeof(int)是%d,sizeof(snum)是%d\n", sizeof(int), sizeof(snum));
		printf("sizeof(3 + 7)是%d\n", sizeof(3 + 7));
		sizeof(snum = 10);
		printf("snum是%hd\n", snum);
/*
 *     进制演示
 *     */
		printf("%d 0%o\n", 0156, 0156);
		printf("%d 0x%x 0X%X\n", 0x6e, 0x6e, 0x6e);
}
/*
 *      二进制练习
 *      */
int Dec_Bin(int num) {
	    printf("%8d\r", num % 2);
		num = num / 2;
		printf("%7d\r", num % 2);
		num = num / 2;
		printf("%6d\r", num % 2);
		num = num / 2;
		printf("%5d\r", num % 2);
		num = num / 2;
		printf("%4d\r", num % 2);
		num = num / 2;
		printf("%3d\r", num % 2);
		num = num / 2;
		printf("%2d\r", num % 2);
		num = num / 2;
		printf("%d\n", num % 2);
		return 0;
}
/*
 *     二进制作业
 *     */
int Dec_bin2(int num) {

	    int base = 128;
		printf("%d", num / base);
		num = num % base;
		base = base / 2;
		printf("%d", num / base);
		num = num % base;
		base = base / 2;
		printf("%d", num / base);
		num = num % base;
		base = base / 2;
		printf("%d", num / base);
		num = num % base;
		base = base / 2;
		printf("%d", num / base);
		num = num % base;
		base = base / 2;
		printf("%d", num / base);													num = num % base;
		base = base / 2;
		printf("%d", num / base);
		num = num % base;
		base = base / 2;
		printf("%d\n", num / base);
																					return 0;
}
/*
 *     二进制用处演示
 *     */
void Binaty(void) {
	    char ch = 300;
		int num = 0;
		printf("%hhd\n", ch);
		ch = 200;
		printf("%hhd\n", ch);
		num = ch;
		printf("%d\n", num);
		printf("&num是%p\n", &num);
}

/*
 *     操作符演示
 *     */
void opr_display(void) {

	    int num = 0;
		char ch = 0;
		num = (2 + 3, 7 + 4);
		printf("num是%d\n", num);
		printf("(ch = 300)是%d\n", (ch = 300));
		num = ch = 200;
		printf("num是%d,ch是%d\n", num, ch);
		num = 10;
		num *= 2 + 3;
		printf("num是%d\n", num);
}
/*
    闰年作业
*/

int leap(int year) {
    int res = 0;

    res = (!(year % 4) && (year % 100)) || (!(year % 400));
    printf("结果是%d\n", res);
    return res;
}

/*
    三目表达式演示
*/

int three_choice(int num) {
    
    num = num >= 0 ? num : 0 - num;
    printf("绝对值是%d\n", num);
    return num;
}

/*
    类型转换演示
*/

void type_display() {
    printf("sizeof(1 ? 1 : 0.9)是%d\n", sizeof(1 ? 1 : 0.9));
    printf("-7 + 3 > 0是%d\n", -7 + 3 > 0);
    printf("-7 + 3u > 0是%d\n", -7 + 3u > 0);
    printf("300是%d\n", 300);
    printf("(char)300是%d\n", (char)300);
}

/*
    天数练习
*/

int compute_day(int year, int month) {
   
    if (month == 1 || month == 3 || month == 5 ||
       month == 7 || month == 8 || month == 10 ||
       month == 12) {
        printf("一共有31天\n");
    }
    else if (month == 2) {
        if ((!(year % 4) && year % 100) || (!(year % 400))) {
            printf("一共有29天\n");
        }
        else {
            printf("一共有28天\n");
        }
    }
    else {
        printf("一共有30天\n");
    }
    return 0;
}

/*
    二进制作业
*/

int Dec_Bin3(int num) {
    
    unsigned char uch = 0x80;

    printf("%d", (num & uch) != 0);
    uch >>= 1; 
    printf("%d", (num & uch) != 0);
    uch >>= 1;
    printf("%d", (num & uch) != 0);
    uch >>= 1; 
    printf("%d", (num & uch) != 0);
    uch >>= 1; 
    printf("%d", (num & uch) != 0);
    uch >>= 1; 
    printf("%d", (num & uch) != 0);
    uch >>= 1; 
    printf("%d", (num & uch) != 0);
    uch >>= 1; 
    printf("%d", (num & uch) != 0);
    printf("\n");
    return 0;
}


/*
    for练习
*/

int display_char() {
    char ch = 0;
    for (ch = 'Z';ch >= 'A';ch--) {
        printf("%c ", ch);
    }
    printf("\n");
    return 0;
}

/*
    break演示
*/

int keyword_use1() {
    int num = 0;
    for (num = 1;num <= 10;num++) {
        printf("%d ", num);
        if (num == 7) {
            break;
        }
    }
    printf("\n");
    printf("num是%d\n", num);
    return 0;
}

/*
    continue演示
*/

int keyword_use2() {
    int num = 0;
    for (num = 1;num <= 10;num++) {
        if (num == 7) {
            continue;
        }
        printf("%d ", num);
    }
    printf("\n");
    return 0;
}

/*
    二进制数位练习
*/

int arr_bin() {
    int bit[8], num = 0;
    for (num = 0;num <= 6;num++) {
        printf("请输入一个数字：");
        scanf("%d", bit + num);
    }
    bit[7] = 0;
    for (num = 0;num <= 6;num++) {
        bit[7] ^= bit[num];
    }
    for (num = 0;num <= 7;num++) {
        printf("%d", bit[num]);
    }
    printf("\n");
    return 0;
}

/*
    随机数演示
*/

#include <time.h>
int use_rand() {
    srand(time(0));
    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());
    return 0;
}
 
/*
    数组作业
*/
int string_display() {
    int num = 0, arr[5] = {}, pos = 4;
    printf("请输入一个数字：");
    scanf("%d", &num);
    //拆出所有数位并记录在数组中
    do {
        arr[pos] = num % 10;
        num /= 10;
        pos--;
    } while (num);
    //打印数组中所有有效数位
    for (pos = pos + 1;pos <= 4;pos++) {
        printf("%d ", arr[pos]);
    }
    printf("\n");
    return 0;
}

/*
    一维数组和二维数组关系演示
*/

int arr1toarr2() {
    int arr[5] = {};
    int arr1[3][2] = {};
    (&arr)[0][3] = 10;
    printf("arr[3]是%d\n", arr[3]);
    printf("&arr是%p,arr是%p\n", &arr, arr);
    printf("&arr + 1是%p,arr + 1是%p\n", &arr + 1, arr + 1);
    printf("sizeof(arr1[1])是%d\n", sizeof(arr1[1]));
    return 0;
}

/*
    随机数作业
*/

int lottery() {
    int lottery[7] = {}, num = 0;
    srand(time(0));
    //生成彩票中的所有数字
    for (num = 0;num <= 6;num++) {
        lottery[num] = rand() % 36 + 1;
    }
    //把数组中的数字依次打印在屏幕上
    for (num = 0;num <= 6;num++) {
        printf("%d ", lottery[num]);
    }
    printf("\n");
    return 0;
}

/*
    二维数组演示
*/
 
int arrary2() {
    int arr[3][2];   //二维数组声明
    int row = 0, col = 0, num = 1;
    arr[1][0] = 10;
    for (row = 0;row <= 2;row++) {
        for (col = 0;col <= 1;col++) {
            arr[row][col] = num;
            num++;
        }
    }   
    for (row = 0;row <= 2;row++) {
        for (col = 0;col <= 1;col++) {
            printf("%d ", arr[row][col]);
        }
        printf("\n");
    }
    return 0;
}

/*
    二维数组练习
*/

int arr2_exercise() {
    int arr[5][5] = {}, pos = 0, row = 0, col = 0;
    for (pos = 0;pos <= 3;pos++) {
        arr[0][pos] = 1;
    }
    for (pos = 0;pos <= 3;pos++) {
        arr[pos][4] = 2;
    }
    for (pos = 1;pos <= 4;pos++) {
        arr[4][pos] = 3;
    }
    for (pos = 1;pos <= 4;pos++) {
        arr[pos][0] = 4;
    }
    for (row = 0;row <= 4;row++) {
        for (col = 0;col <= 4;col++) {
            printf("%d", arr[row][col]);
        }
        printf("\n");
    }
    return 0;
}

/*
    素数作业
*/

int su(int num) {
    int val = 0;
    for (val = 2;val <= num - 1;val++) {
        if (!(num % val)) {
            return 0;
        }
    }
    return 1;
}






