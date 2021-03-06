//分数类的各种运算符重载
#include <iostream>
using namespace std;

class F
{
private:
	int m_s;
	int m_m;
public:
	//有参的构造函数
	F(int s = 0,int m = 1):m_s(s),m_m(m){}
	//支持输出运算符重载
	friend ostream& operator<<(ostream& os,const F& f)
	{
		return os << f.m_s << '/' << f.m_m;
	}
	//支持 负号 运算符
	F operator-(void)
	{
		return F(-m_s,m_m);
	}
	//前缀++运算符
	F& operator++(void)
	{
		m_s++;
		return *this;
	}
	//后缀++运算符
	const F operator++(int)
	{
		F f = *this;
		m_s++;
		return f;
	}
};

int main(void)
{
	F f(2,3);
	cout << "f = " << f << endl;
	cout << "-f = " << -f << endl;
	cout << "f++ = " << f++ << endl;
	cout << "f = " << f << endl;
	cout << "++f = "  << ++f << endl;
	return 0;
}
