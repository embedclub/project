//运算符的重载
#include <iostream>
using namespace std;

class Complex//复数类: 3+2i;
{
private:
	int m_r; //实部
	int m_i;//虚部
public:
	//有参的构造函数
	Complex(int r = 0,int i = 0):m_r(r),m_i(i){}
	//声明一个友元函数
	friend ostream& operator<<(ostream& os,const Complex& c);
	//输入运算符重载函数
	friend istream& operator>>(istream& is,Complex& c)
	{
		is >> c.m_r >> c.m_i;
		return is;
	}
};

//自定义一个输出函数
ostream& operator<<(ostream& os,const Complex& c)
{
	os << c.m_r << '+' << c.m_i << 'i';
	return os;
}

int main(void)
{
	Complex c1(2,3);
	// cout.operator<<(c1); // 不可取
	// operator<<(cout,c1);
	// operator<<(cout,c1).operator<<(endl)
	cout << c1 << endl;
	
	Complex c2;
	cout << "c2 = " << c2 << endl;
	// cout 是ostream类型
	// cin  是istream类型
	// cin.operator>>(c2); //不可取
	// operator>>(cin,c2);
	cin >> c2;
	cout << "输入之后：c2 = " << c2 << endl;
	return 0;
}
