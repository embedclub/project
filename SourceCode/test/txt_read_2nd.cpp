/****************************************************************
 *�ڶ���Ķ�ȡtxt�ļ��Ĵ����
 *���ϸĽ������������Ĺ��̹�^~^
 *****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include "txt_read.h"

double read_txt(char* filename,int n)
{
	double acc = 0.0;                   //���շ��صļ��ٶ�ֵ
	unsigned char buff = '0';       //�ַ������� 
	int i = 0, count = 0, size = 0; 
	
	unsigned char str[20], acc_x[15], acc_y[15], acc_z[15];      //x����ٶ�ֵ������ 
	double accx = 0.0, accy = 0.0, accz = 0.0;	    //x����ٶ�ֵ 
	 
	FILE *fp=fopen(filename,"r");
	if(NULL==fp)			       //�ļ�������ʱ�����ء��޷����ļ��� 
	{
		printf("can't open file\n");
		return -1;
	}
	
	memset(acc_x,0,15);           //�������Ĵ洢�ռ� 
	memset(acc_y,0,15);
    memset(acc_z,0,15);
	//�������ݶ���Ҫ�޸Ĺ�

	while ((buff = fgetc(fp)) != EOF) {
		size = fread(str, sizeof(char), 15, fp);
		printf("һ�����%d����������\n", size);
		printf("%s\n", str);
		while(1);
	}
	
}

