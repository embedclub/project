//分数类中的运算符重载
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
	//输出运算符重载
	friend ostream& operator<<(ostream& os,const F& f)
	{
		// os.operator<<(f.m_s);
		// cout.operator<<(int);
		os << f.m_s << '/' << f.m_m;
		return os;
	}
	friend istream& operator>>(istream& is,F& f)
	{
		is >> f.m_s >> f.m_m;
		return is;
	}
};

int main(void)
{
	F f(2,3);
	//operator<<(cout,f);
	cout << "f = " << f << endl;
	cin >> f;
	cout << "f = " << f << endl;
	return 0;
}
