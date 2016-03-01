/****************************************************************
 *第二版的读取txt文件的代码哈
 *不断改进，才是提升的过程哈^~^
 *****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include "txt_read.h"

double read_txt(char* filename,int n)
{
	double acc = 0.0;                   //最终返回的加速度值
	unsigned char buff = '0';       //字符缓冲器 
	int i = 0, count = 0, size = 0; 
	
	unsigned char str[20], acc_x[15], acc_y[15], acc_z[15];      //x轴加速度值缓冲器 
	double accx = 0.0, accy = 0.0, accz = 0.0;	    //x轴加速度值 
	 
	FILE *fp=fopen(filename,"r");
	if(NULL==fp)			       //文件不存在时，返回“无法打开文件” 
	{
		printf("can't open file\n");
		return -1;
	}
	
	memset(acc_x,0,15);           //清空数组的存储空间 
	memset(acc_y,0,15);
    memset(acc_z,0,15);
	//下面内容都需要修改哈

	while ((buff = fgetc(fp)) != EOF) {
		size = fread(str, sizeof(char), 15, fp);
		printf("一共获得%d个整数数据\n", size);
		printf("%s\n", str);
		while(1);
	}
	
}

