//抽象类的使用
#include <iostream>
using namespace std;

class A
{
public:
	//纯虚函数
	virtual void foo(void) = 0;
};

class B : public A
{
public:
	// 覆盖
	void foo(void)
	{
		cout << "B类中的foo函数" << endl;
	}
	void show(void)
	{
		cout << "B类中的show函数" << endl;
	}
};

class C : public B
{
public:
	void foo(void)
	{
		cout << "C类中的foo函数" << endl;
	}
};

int main(void)
{
	//A a; 抽象类不能实例化对象
	B b;
	b.foo();
	b.show();

	cout << "---------------" << endl;
	C c;
	c.foo();
	c.show();
	
	cout << "---------------" << endl;
	B& rb = c;
	rb.foo();
	rb.show();

	A& ra = c;
	ra.foo();
	return 0;
}
