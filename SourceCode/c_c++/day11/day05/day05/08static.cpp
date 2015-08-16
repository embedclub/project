//静态成员的使用
#include <iostream>
using namespace std;

class A
{
private:
	int m_data;
public:
	//声明静态成员变量
	static int s_data;
public:
	//无参的构造函数
	A(void):m_data(0){}
	//打印的函数
	void print(void)
	{
		cout << "m_data = " << m_data << endl;
		cout << "s_data = " << s_data << endl;
		getData();
	}
public:
	//定义一个静态成员函数
	static int getData(void)
	{
		//cout << "m_data = " << m_data << endl;
		//print();
		return s_data;
	}
};

//静态成员变量的定义
int A::s_data = 100;

int main(void)
{
	A a;
	a.print();
	cout << "A::s_data = " << A::s_data << endl;//100

	cout << "a.s_data = " << a.s_data << endl;//100
	a.s_data = 200;
	A a2;
	cout << "a2.s_data = " << a2.s_data << endl;//200
	
	// A a; sizeof(A) = sizeof(a)
	cout << "sizeof(A) = " << sizeof(A) << endl;// 4

	cout << "--------------------" << endl;
	cout << "获取的数据是：" << A::getData() << endl;;
	cout << "使用对象获取的数据是：" << a.getData() << endl;
	return 0;
}
