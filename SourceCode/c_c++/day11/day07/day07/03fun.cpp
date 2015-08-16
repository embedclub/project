//函数操作符()的重载
#include <iostream>
using namespace std;

class Square
{
public:
	// ()操作符重载
	int operator()(int i)
	{
		return i*i;
	}
	double operator()(double d)
	{
		return d*d;
	}
};

int main(void)
{
	Square s;
	// s.operator()(10);
	cout << "计算的结果是：" << s(10) << endl;
	cout << "计算的结果是：" << s(3.14) << endl;
	return 0;
}
