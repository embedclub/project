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
	//提供一个成员形式的+运算符重载
	Complex operator+(const Complex& c) const
	{
		//创建一个匿名对象 返回
		return Complex(m_r+c.m_r,m_i+c.m_i);
	}
	//提供一个成员形式的-运算符重载
	Complex operator-(const Complex& c) const
	{
		return Complex(m_r-c.m_r,m_i-c.m_i);
	}
	// += 运算符重载
	Complex& operator+= (const Complex& c)
	{
		/*m_r += c.m_r;
		m_i += c.m_i;
		return *this;*/
		return *this = *this + c;
	}
	// -= 运算符重载
	Complex& operator-=(const Complex& c)
	{
		/*m_r -= c.m_r;
		m_i -= c.m_i;
		return *this;*/
		return *this = *this - c;
	}
	//非成员形式去重载+运算符
	/*friend Complex operator+(const Complex& c1,const Complex& c2) 
	{
		cout << "非成员形式的重载" << endl;
		return Complex(c1.m_r+c2.m_r,c1.m_i+c2.m_i);
	}*/

	//类类型 和 int类型之间的+重载
	Complex operator+(int i)
	{
		return Complex(m_r+i,m_i);
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
	
	cout << "-------------------" << endl;
	// Complex c3 = c1.operator+(c2);
	// Complex c3 = operator+(c1,c2);
	// c3.operator=(c1.operator+(c2));
	Complex c3 = c1 + c2;
	cout << "c3 = " << c3 << endl;
	cout << "c3 - c2 = " << c3-c2 << endl;
	
	cout << "------------------" << endl;
	int a = 10,b = 20;
	(a += b) += b;
	cout << "a = " << a << endl;//50
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	// c1.operator+=(c2).operator+=(c2);
	(c1 += c2) += c2;
	cout << "c1 = " << c1 << endl;
	(c1 -= c2) -= c2;
	cout << "c1 = " << c1 << endl;
	
	cout << "-----------------" << endl;
	cout << "c1 = " << c1 << endl;
	// c1.operator+(100);
	cout << "c1 + 100 = " << c1+100 << endl;
	return 0;
}
