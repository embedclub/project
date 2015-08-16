//钻石继承的使用
#include <iostream>
using namespace std;

class A
{
public:
	int m_n;
public:
	//有参的构造函数
	A(int n = 0):m_n(n)
	{
		cout << "构造A" << endl;
	}
};

// 虚继承，表示不会去构造其基类部分
class B : virtual public A
{
public:
	//有参的构造函数
	B(int n = 0):A(n)
	{
		cout << "构造B" << endl;
	}
	//设置成员变量的值
	void set(int n)
	{
		m_n = n;
	}
	//打印函数
	void show(void)
	{
		cout << "B类中的show函数" << endl;
	}
};

class C : virtual public A
{
public:
	C(int n = 0):A(n)
	{
		cout << "构造C" << endl;
	}
	//获取成员变量的值
	int get(void)
	{
		return m_n;
	}
	void show(char c)
	{
		cout << "C类中的show函数" << endl;
	}
};

class D : public B,public C
{
public:
	D(int n = 0):B(n),C(n),A(n)
	{
		cout << "构造D" << endl;
	}
	// 名字隐藏
	void show(int i,char c)
	{
		cout << "D类中的show函数" << endl;
	}
};

int main(void)
{
	D d(100);
	cout << "成员变量的值是：" << d.get() << endl;
	d.set(200);
	cout << "成员变量的值是：" << d.get() << endl;

	cout << "---------------" << endl;
	//d.show(); B类和C类中show不构成重载
	d.B::show();
	d.C::show('A');
	d.show(34,'A');// D类中的show函数
	return 0;
}
