//析构函数的作用
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
		cout << "析构A" << endl;
	}
};

class B
{
private:
	A* m_a;
public:
	B(void):m_a(new A)
	{
		cout << "B被构造了" << endl;
	}
	~B(void)
	{
		cout << "析构B" << endl;
		delete m_a;
		m_a = NULL;
	}
};

int main(void)
{
	//构造A  构造B 析构B  析构A
	B b;
	return 0;
}
