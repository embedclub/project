//特殊的重载关系
#include <iostream>
using namespace std;

namespace ns1
{
	void foo(int i)
	{
		cout << "ns1::foo中 i = " << i << endl;
	}
}

namespace ns2
{
	void foo(double d)
	{
		cout << "ns2::foo中 d = " << d << endl;
	}
}

int main(void)
{
	using namespace ns1;
	using namespace ns2;
	//两个foo都可见，构成重载
	foo(66); //ns1中的foo函数
	foo(3.14);//ns2中的foo函数

	using ns1::foo;
	foo(66);// ns1
	foo(3.14);// ns1

	using ns2::foo;
	//再次构成重载
	foo(66);//ns1
	foo(3.14);//ns2
	return 0;
}
