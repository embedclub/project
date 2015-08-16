//虚析构的使用
#include <iostream>
using namespace std;

class A
{
public:
	A(void)
	{
		cout << "A被构造了" << endl;
	}
	//虚析构函数
	virtual ~A(void)
	{
		cout << "析构A" << endl;
	}
};

class B : public A
{
public:
	B(void)
	{
		cout << "B被构造了" << endl;
	}
	~B(void)
	{
		cout << "析构B" << endl;
	}
};

int main(void)
{
	B* pb = new B;
	delete pb;
	pb = NULL;
	
	cout << "---------------" << endl;
	A* pa = new B;
	delete pa;
	pa = NULL;
	return 0;
}
