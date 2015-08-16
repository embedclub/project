//析构函数的使用
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
	//析构函数
	~A(void)
	{
		cout << "析构A" << endl;
	}
};

//A g_a;

int main(void)
{
	cout << "主函数开始" << endl;
	// A a
	/*{
		A a;
	}*/
	/*A* pa = new A;
	cout << "在new和delete之间" << endl;
	delete pa;
	pa = NULL;*/
	A* pa = new A[3];
	cout << "在new和delete之间" << endl;
	delete[] pa;
	pa = NULL;
	cout << "主函数结束" << endl;
	return 0;
}
