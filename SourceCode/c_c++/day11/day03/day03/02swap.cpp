//分别使用普通变量、指针、引用作为函数的参数
#include <iostream>
using namespace std;

//值传递 不会交换实参的值
void swap1(int i,int j)
{
	int temp = i;
	i = j;
	j = temp;
}
//址传递，可以交换实参
void swap2(int* pi,int* pj)
{
	int temp = *pi;
	*pi = *pj;
	*pj = temp;
}
//址传递，可以交换实参
void swap3(int& ri,int& rj)
{
	int temp = ri;
	ri = rj;
	rj = temp;
}

//打印的函数
void print(const int& i,const int& j)
{
	cout << "i = " << i << ",j = " << j << endl;
}

int main(void)
{
	int i = 10,j = 20;
	//swap1(i,j); 不能交换
	//swap2(&i,&j);//可以交换
	swap3(i,j); //可以交换
	cout << "i = " << i << ",j = " << j << endl;

	cout << "-----------------" << endl;
	print(i,j); // 20 10
	print(20,10);
	return 0;
}
