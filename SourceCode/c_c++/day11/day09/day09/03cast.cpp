//类型转换的使用
#include <iostream>
using namespace std;

class A
{
public:
	virtual void foo(void){}
};
class B : public A{};
class C : public A{};
class D{};

int main(void)
{
	B b;
	// B* -> A* 类型转换
	A* pa = &b;
	cout << "pa = " << pa << endl;
	// A* -> B* 类型转换
	B* pb = dynamic_cast<B*>(pa);
	cout << "pb = " << pb << endl;
	// 0 假 NULL 表示转换失败,比较安全
	C* pc = dynamic_cast<C*>(pa);
	cout << "pc = " << pc << endl;
	// 转换失败 在运行时做类型检查
	D* pd = dynamic_cast<D*>(pa);
	cout << "pd = " << pd << endl;

	cout << "------------------" << endl;
	pb = static_cast<B*>(pa);
	cout << "pb = " << pb << endl;
	pc = static_cast<C*>(pa);
	cout << "pc = " << pc << endl;
	//编译阶段进行检查
	//pd = static_cast<D*>(pa);
	//cout << "pd = " << pd << endl;
	
	cout << "----------------" << endl;
	// 最不安全的，编译和运行时都不做类型检查
	pb = reinterpret_cast<B*>(pa);
	cout << "pb = " << pb << endl;
	pc = reinterpret_cast<C*>(pa);
	cout << "pc = " << pc << endl;
	pd = reinterpret_cast<D*>(pa);
	cout << "pd = " << pd << endl;
	return 0;
}
