//缺省参数引发的重载冲突
#include <iostream>
using namespace std;

//函数的声明  [1 ~ 3]
void foo(int i,char c = 'A',char* p = NULL);
// 1个实参
void foo(int i)
{
	cout << "带有一个参数的foo函数中:i = " << i << endl;
}

int main(void)
{
	foo(66,'B',"hello");
	foo(66,'B');
	//foo(66); 调用函数有歧义
	//foo(); error
	return 0;
}

//函数的定义
void foo(int i,char c,char* p)
{
	cout << "在有三个参数的foo函数中：i = " << i << ",c = " << c << ",p = " << (p?p:"空指针") << endl; 
}
