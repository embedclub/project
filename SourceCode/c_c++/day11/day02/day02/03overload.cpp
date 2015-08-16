//重载匹配的原则
#include <iostream>
using namespace std;

//char -> int 升级转换
void bar(char* p,int i)
{
	cout << "bar(1)函数" << endl;
}
// char* -> const char* 常量转换
void bar(const char* p,char c)
{
	cout << "bar(2)函数" << endl;
}

// short -> char 标准转换
void fun(char c)
{
	cout << "fun(1)函数" << endl;
}
// short -> int 升级转换
void fun(int i)
{
	cout << "fun(2)函数" << endl;
}
// short -> long long 过分的升级转换
void fun(long long l)
{
	cout << "fun(3)函数" << endl;
}

// int -> ...  省略匹配
void hum(double f,...)
{
	cout << "hum(1)函数" << endl;
}
// double -> int 标准转换
void hum(int i,int j)
{
	cout << "hum(2)函数" << endl;
}

int main(void)
{
	//char* p,c;
	//bar(p,c);
	
	short s;
	fun(s);

	hum(3.14,66);
	return 0;
}
