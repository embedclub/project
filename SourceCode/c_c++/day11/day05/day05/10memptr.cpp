//成员指针的使用
#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	string m_name;//姓名
	//设置姓名的成员函数
	void setName(const string& name)
	{
		m_name = name;
	}
};

int main(void)
{
	//1.定义指向成员变量的指针
	string Student::*pName;
	//2.给指针进行赋值
	pName = &Student::m_name;
	//3.使用指针
	Student s;
	// s.*(&m_name) => s.m_name
	s.*pName = "张飞";
	cout << "s.m_name = " << s.m_name << endl;

	cout << "------------" << endl;
	Student s2;
	s2.*pName = "关羽";
	cout << "s2.m_name = " << s2.m_name << endl;
	
	cout << "-----------" << endl;
	//指向成员函数指针的定义及初始化
	void (Student::*pSetName)(const string& name) = &Student::setName;
	//使用函数指针
	// *pSetName => *(&setName) => setName
	// s.setName("黄忠");
	(s.*pSetName)("黄忠");
	cout << "s.m_name = " << s.m_name << endl;
	(s2.*pSetName)("马超");
	cout << "s2.m_name = " << s2.m_name << endl;
	return 0;
}
