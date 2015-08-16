//引用作为函数的返回值
#include <iostream>
using namespace std;
/*
int& foo(void)
{
	int num = 100;
	//cout << "&num = " << &num << endl;
	return num;
}*/

void makeTrouble(void)
{
	int a = 200;
	int b = 300;
	//cout << "&a = " << &a << ",&b = " << &b << endl;
}

int& foo2(void)
{
	//生命周期变长了
	static int num = 100;
	return num;
}

int g_num = 100;
int& foo3(void)
{
	return g_num;
}

int& foo4(void)
{
	int* pi = new int(100);
	return *pi;
}

int& foo5(int& r)
{
	return r;
}

struct S
{
	int n;
	int& foo6(void)
	{
		return n;
	}
};

int main(void)
{
	//int& rn = foo4();
	//makeTrouble();
	//cout << "&rn = " << &rn << endl;
	//cout << "rn = " << rn << endl;
	
	int num = 100;
	int& rn = foo5(num);
	makeTrouble();
	// rn实际上用的就是num的内存空间
	cout << "rn = " << rn << endl;

	S s;
	s.n = 100;
	int& rm = s.foo6();
	makeTrouble();
	cout << "rm = " << rm << endl;
	return 0;
}
