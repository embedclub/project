#include<stdio.h>
#include<string.h>
#include<math.h>
#include "txt_read.h"

double read_txt(char* filename,int n)
{
	double acc = 0.0;                   //最终返回的加速度值
	unsigned char buff = '0';       //字符缓冲器 
	int i = 0, count = 0; 
	
	unsigned char acc_x[15], acc_y[15], acc_z[15];      //x轴加速度值缓冲器 
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
	double ctof(unsigned char *a); //字符转双精度函数 
	
	while(!feof(fp)) {
		buff=fgetc(fp);	
		if(buff==',')   count++; 
		if(count==15*(n-1))	break;	
	}
	count = 0;	
	while(!feof(fp))
	{
		buff=fgetc(fp);	
		if(buff==',')   count++; 
		if(count==4)	break;	
	}
	
	while ((buff=fgetc(fp))!= ',')     
	{
		acc_x[i]=buff;
		i++;
	}
	accx=ctof(acc_x);
	printf("%f\n",accx);
	i=0;
			
	while ((buff=fgetc(fp))!= ',')     
	{
		acc_y[i]=buff;
		i++;
	}
	accy=ctof(acc_y);
	printf("%f\n",accy);
	i=0;
	
	while ((buff=fgetc(fp))!= ',')     
	{
		acc_z[i]=buff;
		i++;
	}
	accz=ctof(acc_z);
	printf("%f\n",accz);
	i=0;
	
	acc=sqrt(accx*accx+accy*accy+accz*accz);
	printf("%f",acc);
	
    printf("\n");
	fclose(fp);
	return acc;
	
}

 double ctof(unsigned char *a)       //将字符数组转换成相应double类型数据 
{
	int j = 0;
	double t=10;
	double num=0;
	while(a[j]!='\0')
	{
		if(a[j]>='0'&&a[j]<='9')
		{
			if(t==10)	num=num*t+a[j]-48;
			else {
					num+=(a[j]-48)*t;
					t=t*0.1;
			      }
		}
		if(a[j]=='.')		t=0.1;
		j++;
	}
	if(a[0]=='-')		num=0-num;
	return (num);
}


