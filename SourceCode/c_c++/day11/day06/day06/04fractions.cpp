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
	// + 运算符重载
	F operator+(const F& f) const
	{
		//分母相乘做分母,分子*f的分母+分母*f的分子作为新的分子
		return F(m_s*f.m_m+m_m*f.m_s,m_m*f.m_m);
	}
	F operator-(const F& f) const
	{
		return F(m_s*f.m_m-m_m*f.m_s,m_m*f.m_m);
	}
	F& operator+=(const F& f)
	{
		return *this = *this + f;
	}
	F& operator-=(const F& f)
	{
		return *this = *this - f;
	}
};

int main(void)
{
	F f(2,3);
	//operator<<(cout,f);
	cout << "f = " << f << endl;
	F f2;
	cin >> f2;
	cout << "f2 = " << f2 << endl;

	cout << "---------------" << endl;
	// f.operator+(f2);
	cout << "f+f2 = " << f+f2 << endl;
	cout << "f-f2 = " << f-f2 << endl;
	// f.operator+=(f2);
	cout << "f+=f2的结果：" << (f+=f2) << endl;
	cout << "f-=f2的结果是：" << (f-=f2) << endl;
	return 0;
}
