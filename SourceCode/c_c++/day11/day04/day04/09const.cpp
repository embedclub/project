//const修饰的对象和成员函数
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string m_name;
	mutable int m_age;
public:
	//有参的构造函数
	Student(const string& name,int age):m_name(name),m_age(age){}
	//打印的函数
	void show(void)
	{
		cout << "我是" << m_name << ",今年" << m_age << "岁了" << endl;
	}
	//设置姓名的函数
	void setName(const string& name)
	{
		m_name = name;
	}
	//获取姓名的函数
	string getName(void) const//修饰this指针
	{
		m_age = 40;
		//m_name = ""; this->m_name = ""; const Student* ps; // error
		//setName("");//this->setName(""); error
		cout << "const修饰的成员函数" << endl;
		return m_name;
	}
	string getName(void)
	{
		cout << "普通成员函数" << endl;
		return m_name;
	}
};

int main(void)
{
	Student s("张飞",30);
	s.show();
	
	cout << "获取到的姓名是：" << s.getName() << endl;

	cout << "-------------" << endl;
	const Student& rs = s;
	cout << "引用获取的姓名是：" << rs.getName() << endl;
	//rs.setName("关羽"); error
	const Student* ps = &s;
	cout << "指针获取的姓名是：" << ps->getName() << endl;
	//ps->setName("赵云");error
	return 0;
}
