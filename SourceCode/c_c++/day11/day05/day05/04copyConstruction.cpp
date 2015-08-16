//拷贝构造函数的使用
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string m_name;
	int m_age;
public:
	//打印函数
	void show(void)
	{
		cout << "我是" << m_name << ",今年" << m_age << "岁了" << endl;
	}
	//有参的构造函数
	Student(const string& name,int age):m_name(name),m_age(age){}
	//自定义拷贝构造函数
	Student(const Student& s):m_name(s.m_name),m_age(s.m_age)
	{
		cout << "自定义拷贝构造函数" << endl;
	}
};

int main(void)
{
	Student s("张飞",30);
	s.show();
	
	cout << "------------------" << endl;
	Student s2(s);
	s2.show();
	Student s3 = s;//Student s3(s);
	s3.show();
	Student* ps = new Student(s);
	ps->show();
	delete ps; ps = NULL;
	
	// s2.operator=(s);
	//s2 = s;
	return 0;
}
