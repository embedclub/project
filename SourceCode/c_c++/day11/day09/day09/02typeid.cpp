//typeid的使用
#include <iostream>
#include <typeinfo>
using namespace std;

class Student{};
class A
{
	virtual void foo(void){}
};
class B : public A{};
class C : public A{};

int main(void)
{
	int n = 10;
	cout << typeid(int).name() << endl;
	cout << typeid(n).name() << endl;
	cout << typeid(unsigned int).name() << endl;
	cout << typeid(char*).name() << endl;
	cout << typeid(double**).name() << endl;
	short sa[10];
	cout << typeid(sa).name() << endl;
	cout << typeid(Student).name() << endl;
	
	cout << "-------------" << endl;
	B b;
	A& ra = b;
	// typeid 获取ra所真正指向的对象类型,也就是可以获取运行时类型信息
	cout << typeid(ra).name() << endl;//1B

	cout << "-------------" << endl;
	A* pa = new B;
	if(typeid(*pa) == typeid(B))
	{
		cout << "pa指向B类型的对象" << endl;
	}
	if(typeid(*pa) == typeid(C))
	{
		cout << "pa指向C类型的对象" << endl;
	}
	return 0;
}
