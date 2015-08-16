//声明  定义  初始化的比较
#include <iostream>
using namespace std;

class A
{
public:
	//无参的构造函数
	A(void)
	{
		cout << "A被构造了" << endl;
	}
};

class B
{
private:
	A m_a;//A类型的对象作为成员变量
public:
	B(void)
	{
		cout << "构造B" << endl;
	}
};

int main(void)
{
	B b;
	return 0;
}
