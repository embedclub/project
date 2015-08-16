//this指针用于返回自引用的场合
#include <iostream>
using namespace std;

//自定义一个计数类
class Counter
{
private:
	int m_cn;
public:
	//有参的构造函数
	Counter(int cn = 0):m_cn(cn){}
	//加1的成员函数
	Counter& inc(void)
	{
		m_cn++; //计数加1
		return *this;
	}
	//减1的成员函数
	Counter& dec(void)
	{
		m_cn--;
		return *this;
	}
	//打印的函数
	void print(void)
	{
		cout << m_cn << endl;
	}
};

int main(void)
{
	Counter c;
	/*c.inc();
	c.inc();
	c.inc();
	c.dec();
	c.print();//2 */
	c.inc().inc().inc().dec().print();//2
	c.print(); // 2
	return 0;
}
