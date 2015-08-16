//各种类型转换算子的使用
#include <iostream>
using namespace std;

int main(void)
{
	char* pc;
	// char* -> void* 可以发生隐式类型转换
	void* pv = pc; 
	// void* -> char* 不能发生隐式类型转换,可以使用静态类型转换算子
	//pc = pv;
	// void* -> char*  ok
	pc = static_cast<char*>(pv);
	// char* -> void*  ok
	pv = static_cast<void*>(pc);

	int* pi;
	// int* -> char  不能做隐式类型转换
	//char c = pi;
	char c;
	// char -> int* 不能做隐式类型转换
	//pi = c;
	//c = static_cast<char>(pi); error
	//pi = static_cast<int*>(c); error

	volatile/*易变的*/ const int num = 200;
	// num = 100; error
    // const int* -> int* 转换失败
	//int* pn = &num;
	int* pn = const_cast<int*>(&num);
	*pn = 100;
	// 100 100 扫描内存区域
	cout << "num = " << num << ",*pn = " << *pn << endl;

	int n = 100;
	// int* -> char*
	char* ps = reinterpret_cast<char*>(&n);
	cout << "*ps = " << *ps << endl; //d
	return 0;
}
