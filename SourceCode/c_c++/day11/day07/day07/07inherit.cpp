//继承的使用
#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string m_name;
	int m_age;
public:
	Person(const string& name,int age):m_name(name),m_age(age)
	{
		cout << "我是" << m_name << "，今年" << m_age << "岁了" << endl;
	}
	void eat(const string& food)
	{
		cout << food << "真好吃" << endl;
	}
};

class Teacher : public Person
{
private:
	string m_job;
public:
	Teacher(const string& name,int age,const string& job):Person(name,age),m_job(job)
	{
		cout << "我是教师，职称是：" << m_job << endl;
	}
	void educate(const string& lesson)
	{
		cout << "我在教" << lesson << endl;
	}
};

int main(void)
{
	Teacher t("张飞",30,"教练");
	t.educate("武术");
	t.eat("凉拌牛肉");
	return 0;
}
