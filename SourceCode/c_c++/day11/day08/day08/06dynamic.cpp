//多态的底层实现
#include <iostream>
using namespace std;

class A
{
//private:
//	int m_n;
public:
	//有了虚函数之后，多4个字节
	// 指针 指向一个虚函数表的地址
	// 虚函数表 是一个函数指针数组
	virtual void foo(void)
	{
		cout << "A类中的foo函数" << endl;
	}
	virtual void bar(void)
	{
		cout << "A类中的bar函数" << endl;
	}
};

class B : public A
{
public:
	// 虚函数覆盖,foo也是一个虚函数
	void foo(void)
	{
		cout << "B类中的foo函数" << endl;
	}
};

int main(void)
{
	//对于一个空类来说sizeof大小是1
	//cout << "sizeof(A) = " << sizeof(A) << endl;
	//cout << "sizeof(B) = " << sizeof(B) << endl;

	/*A* pa = new B;
	pa->foo();
	pa->bar();
	delete pa;
	pa = NULL;*/
	
	//定义一个指向虚函数的函数指针
	typedef void (*pFun)(void);
	// 指向函数指针的指针
	typedef pFun* ppFun;
	A a;
	ppFun pp = *((ppFun*)&a);
	cout << "虚函数表的首地址是：" << (void*)pp << endl;
	cout << "虚函数表中第一个元素是：" << (void*)pp[0] << endl;
	cout << "虚函数表中第二个元素是：" << (void*)pp[1] << endl;
	pp[0]();
	pp[1]();

	cout << "------------------" << endl;
	B b;
	pp = *((ppFun*)&b);
	cout << "B类中虚函数表的首地址是：" << (void*)pp << endl;
	cout << "虚函数表中第一个元素是：" << (void*)pp[0] << endl;
	cout << "虚函数表中第二个元素是：" << (void*)pp[1] << endl;
	pp[0]();
	pp[1]();
	return 0;
}
