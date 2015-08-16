//this指针的初识
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string m_name;
	int m_age;
public:
	//有参的构造函数
	//Student(const string& name,int age)
	Student(const string& m_name,int m_age)
	{
		// (*this).m_name = m_name;
		// s.m_name = m_name;
		this->m_name = m_name;
		this->m_age = m_age;
		cout << "在构造函数中：this = " << this << endl;
	}
	//展示自我
	void show(void)
	{
		cout << "我是" << m_name << ",今年" << m_age << "岁了" << endl;
		cout << "在show函数中：this = " << this << endl;
	}
};

int main(void)
{
	Student s("张飞",30);
	s.show();
	cout << "在主函数中：&s = " << &s << endl; 

	cout << "-------------------" << endl;
	Student s2("关羽",35);
	s2.show();
	cout << "在主函数中：&s2 = " << &s2 << endl;
	return 0;
}
