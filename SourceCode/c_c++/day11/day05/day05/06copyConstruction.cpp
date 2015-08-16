//拷贝构造的时机
#include <iostream>
using namespace std;

class A
{
public:
	A(void)
	{
		cout << "自定义构造函数" << endl;
	}
	A(const A& a)
	{
		cout << "自定义拷贝构造函数" << endl;
	}
};

//void foo(A a){} //A a = a1 调用拷贝构造
//A foo(A a){ return a;} //调用两次拷贝构造
//A& foo(A a){return a;} //调用一次拷贝构造
//A& foo(A& a){return a;} //调用 0 次
//因为局部变量生命周期短暂，构造完毕之后还得销毁，于是编译器优化，直接构造新对象完毕,所以只调用一次构造函数即可
A foo(void)
{
	A a;
	return a;
}

int main(void)
{
	A a1; //构造函数
	A a2(a1);
	A a3 = a2;
	A* pa = new A(a3);

	cout << "---------------" << endl;
	foo();
	return 0;
}
