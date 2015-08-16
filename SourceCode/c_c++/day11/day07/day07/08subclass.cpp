//子类中的析构函数使用
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

class B : public A
{
public:
	B(void)
	{
		cout << "B被构造了" << endl;
	}
	/*~B(void)
	{
		cout << "析构B" << endl;
	}*/
};

int main(void)
{
	// 构造A 构造B 析构B 析构A
	B* pb = new B;
	delete pb;
	pb = NULL;
	
	cout << "-------------------" << endl;
	// 构造A 构造B  析构A
	A* pa = new B;
	delete pa;
	pa = NULL;
	return 0;
}
