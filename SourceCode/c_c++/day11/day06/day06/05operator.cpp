//运算符的重载
#include <iostream>
using namespace std;

class Complex
{
private:
	int m_r;
	int m_i;
public:
	//有参的构造函数
	Complex(int r = 0,int i = 0):m_r(r),m_i(i){}
	//支持输出运算符重载
	friend ostream& operator<<(ostream& os,const Complex& c)
	{
		return os << c.m_r << '+' << c.m_i << 'i';
	}
	//重载 - 运算符
	Complex operator-(void)
	{
		return Complex(-m_r,-m_i);
	}
	//重载后缀++运算符
	//const/*返回值不可改变*/ Complex operator++(int)
	/*{
		Complex c = *this;
		m_r++;
		m_i++;
		return c;
	}*/
	//使用友元函数的形式去重载后缀++运算符
	friend const Complex operator++(Complex& c,int)
	{
		Complex c1 = c;
		c.m_r++;
		c.m_i++;
		return c1;
	}
	//重载前缀++运算符
	Complex& operator++(void)
	{
		++m_r;
		++m_i;
		return *this;
	}
	//重载后缀--运算符
	const Complex operator--(int)
	{
		Complex c = *this;
		m_r--;
		m_i--;
		return c;
	}
	//重载前缀--运算符
	Complex& operator--(void)
	{
		--m_r;
		--m_i;
		return *this;
	}
};

int main(void)
{
	Complex c1(2,3);
	cout << "c1 = " << c1 << endl;
	// c1.operator-();
	// operator-(c1);
	cout << "-c1 = " << -c1 << endl;
	
	cout << "--------------------" << endl;
	int m = 10;
	cout << "m++ = " << m++ << endl;//10
	cout << "m = " << m << endl;//11
	//(m++)++;//m++返回的是++之前的临时值，并不是m本身，临时值不能再次进行++运算
	//cout << "m = " << endl;

	int n = 10;
	cout << "++n = " << ++n << endl;//11
	cout << "n = " << n << endl;// 11
	++(++n);//++n 返回的是 n的引用 
	// C语言中 ++++n; error
	cout << "n = " << n << endl;//13

	cout << "--------------------" << endl;
	cout << "c1 = " << c1 << endl;
	// c1.operator++(int)
	// operator++(c1,int);
	cout << "c1++ = " << c1++ << endl;
	cout << "c1 = " << c1 << endl;
	//(c1++)++; error
	//cout << "c1 = " << c1 << endl;

	// c1.operator++();
	cout << "++c1 = " << ++c1 << endl;
	cout << "c1 = " << c1 << endl;
	++++c1;
	cout << "c1 = " << c1 << endl;

	cout << "-----------------" << endl;
	cout << "c1-- = " << c1-- << endl;
	cout << "c1 = " << c1 << endl;
 	//c1----;error
	cout << "--c1 = " << --c1 << endl;
	cout << "c1 = " << c1 << endl;
	----c1;
	cout << "c1 = " << c1 << endl;
	return 0;
}
