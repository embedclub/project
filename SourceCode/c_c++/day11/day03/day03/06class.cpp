//类和对象的初始
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	//属性 成员变量
	string m_name;//姓名
	int m_age;//年龄
public:
	//行为 成员函数
	void learn(const string& lesson)
	{
		cout << "我是" << m_name << ",今年" << m_age << "岁了，正在学习" << lesson << endl;
	}
	//设置姓名的成员的函数
	bool setName(const string& name)
	{
		//合法性判断
		if(0 == name.length())
		{
			//设置失败
			return false;
		}
		m_name = name;
		return true;
	}
	//设置年龄的成员函数
	bool setAge(int age)
	{
		if(age < 0 || age > 150)
		{
			return false;
		}
		m_age = age;
		return true;
	}
	//获取姓名的成员函数
	string getName(void)
	{
		return m_name;
	}
	//获取年龄的成员函数
	int getAge(void)
	{
		return m_age;
	}
	//自定义一个带参的构造函数
	Student(const string& name,int age)
	{
		m_name = name;
		m_age = age;
	}
};

int main(void)
{
	//创建一个Student类型的对象,名字为s
	//构造对象
	//实例化对象
	//Student/*数据类型*/ s/*变量名*/; 
	//编译报错，因为是私有的
	//s.m_name = "张飞";
	//s.m_age = 30;
	/*if(!s.setName("张飞"))
	{
		cout << "设置姓名失败" << endl;
		return -1;
	}
	if(!s.setAge(30))
	{
		cout << "设置年龄失败" << endl;
		return -1;
	}
	s.learn("C++");
	cout << s.getName() << ',' << s.getAge() << endl;*/

	cout << "--------------" << endl;
	// string s("hello");
	Student s2("关羽",35);
	cout << s2.getName() << ',' << s2.getAge() << endl;
	return 0;
}
