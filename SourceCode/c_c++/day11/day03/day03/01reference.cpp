//引用作为函数的参数
#include <iostream>
using namespace std;

//值传递  发生数据的拷贝
void fn(int num)
{
	num = 250;
}
//通过址传递可以修改实参的值
void fn2(int* pn)
{
	*pn = 250;
}
//通过引用作为函数的参数也可以修改实参的值
void fn3(int& rn)
{
	rn = 250;
}

//传递的是个地址，为啥不改变实参？
void bar(char* ps)
{
	ps = "world";
}
//练习：编程实现址传递
void bar2(char** pps)
{
	*pps = "world";
}
//引用作为形参修改实参的值
void bar3(char*& rps)
{
	rps = "world";
}

int main(void)
{
	int num = 66;
	fn3(num);
	cout << "num = " << num << endl;

	char* ps = "hello";
	bar3(ps);
	cout << "ps = " << ps << endl;//
	return 0;
}
