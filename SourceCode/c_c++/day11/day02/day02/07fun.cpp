//函数中的参数列表为空时在C++中的处理
#include <iostream>
using namespace std;

int fn();

int main(void)
{
	fn(/*66,3.14,"hello"*/);
	return 0;
}

// 表示不接受任何参数
int fn()
{
	cout << "调用fn函数了" << endl;
}
