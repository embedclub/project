// * -> 间接操作符的重载
#include <iostream>
using namespace std;

class A
{
public:
	A(void)
	{
		cout << "A被构造了" << endl;
	}
	~A(void)
	{
		cout << "析构Ａ" << endl;
	}
	void foo(void)
	{
		cout << "foo()函数调用了" << endl;
	}
};

class PA
{
private:
	A* m_pa;
public:
	//有参的构造函数
	PA(A* pa):m_pa(pa){}
	//析构函数
	~PA(void)
	{
		delete m_pa;
		m_pa = NULL;
	}
	//支持->运算符函数
	A* operator->(void)
	{
		return m_pa;
	}
	A& operator*(void)
	{
		return *m_pa;
	}
};

int main(void)
{
	//A* pa = new A;
	//pa->foo();
	//delete pa;
	//pa = NULL;
	PA pa(new A);
	// pa.operator->() ->foo();
	pa->foo();
	// pa.operator*() .foo();
	(*pa).foo();
	return 0;
}
