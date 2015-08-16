//自定义拷贝构造函数的场合
#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
	char* m_pName;//姓名
	int m_age;
public:
	//有参的构造函数
	Student(const char* pName,int age):m_pName(NULL),m_age(age)
	{
		m_pName = new char[strlen(pName)+1];
		strcpy(m_pName,pName);
	}
	//自定义析构函数
	~Student(void)
	{
		delete[] m_pName;
		m_pName = NULL;
	}
	//打印函数
	void show(void)
	{
		cout << "我是" << m_pName << ",今年" << m_age << "岁了" << endl;
	}
	//自定义拷贝构造函数
	Student(const Student& s):m_pName(NULL),m_age(s.m_age)
	{
		m_pName = new char[strlen(s.m_pName)+1];
		strcpy(m_pName,s.m_pName);
	}
};

int main(void)
{
	Student s1("张飞",30);
	s1.show();
	
	Student s2(s1);
	s2.show();
	return 0;
}
