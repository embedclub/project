//自定义一个函数
#include <iostream>
using namespace std;

//告诉编译器不要对show函数进行换名操作
extern "C" void show(int i,int j)
{
	cout << "在show函数中：i = " << i << "," << j << endl;
}
