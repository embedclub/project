//自定义一个有且只有一个对象的类
//单例类 -> 单例模式
#include <iostream>
using namespace std;

class Singleton
{
private:
	//自定义私有的构造函数
	Singleton(void){}
	//私有的拷贝构造
	Singleton(const Singleton& single){}
	//私有的拷贝赋值运算符函数
	Singleton& operator=(const Singleton& s){}
private:
	// sizeof(对象名) 
    // 声明一个静态成员变量	
	static Singleton s;
public:
	static Singleton& getSingleton(void)
	{
		return s;
	}
};

//定义静态成员变量
Singleton Singleton::s;

int main(void)
{
	//Singleton s1; error;
	//Singleton s2(s1);error
	Singleton& s1 = Singleton::getSingleton();
	cout << "&s1 = " << &s1 << endl;
	Singleton& s2 = Singleton::getSingleton();
	cout << "&s2 = " << &s2 << endl;
	Singleton& s3 = Singleton::getSingleton();
	cout << "&s3 = " << &s3 << endl;
	
	//s1 = s2; error
	//cout << "&s1 = " << &s1 << endl;
	return 0;
}
