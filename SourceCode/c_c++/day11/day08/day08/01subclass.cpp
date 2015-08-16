//子类中的拷贝构造和拷贝赋值
#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string m_name;
	int m_age;
public:
	//有参的构造函数
	Person(const string& name,int age):m_name(name),m_age(age)
	{
		cout << "我是" << m_name << ",今年" << m_age << "岁了" << endl;
	}
	//自定义拷贝构造函数
	Person(const Person& p):m_name(p.m_name),m_age(p.m_age)
	{
		cout << "Person自定义拷贝构造函数" << endl;
	}
};

class Teacher : public Person
{
private:
	string m_job;//职称
public:
	//有参的构造函数
	Teacher(const string& name,int age,const string& job):Person(name,age),m_job(job)
	{
		cout << "我是教师，我的职称是：" << m_job << endl;
	}
	//自定义拷贝构造函数
	Teacher(const Teacher& t):Person(t),m_job(t.m_job)
	{
		cout << "自定义拷贝构造函数" << endl;
	}
};

int main(void)
{
	Teacher t("张飞",30,"教练");
	Teacher t2(t);//拷贝构造函数
	return 0;
}
