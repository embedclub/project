//构造函数的学习
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string m_name;
	int m_age;
public:
	void show(void)
	{
		cout << "我是" << m_name << ",今年" << m_age << "岁了" << endl;
	}
	//带参的构造函数
	/*Student(const string& name = "无名",int age = 0)
	{
		m_name = name;
		m_age = age;
	}*/
	//使用初始化列表的方式进行初始化
	Student(const string& name = "无名",int age = 0):m_name(name),m_age(age){}

	//无参的构造函数
	/*Student(void)
	{
		m_name = "没名";
		m_age = 0;
	}*/
};

int main(void)
{
	Student s("张飞",30);//隐式构造
	s.show();

	// 显式构造
	Student s2 = Student("关羽",35);
	s2.show();
	
	Student ss[3] = {Student("赵云",28),Student("黄忠",40),Student("马超",25)};
	ss[0].show();
	ss[1].show();
	ss[2].show();

	cout << "---------------" << endl;
	Student* ps = new Student("刘备",42);
	ps->show();
	delete ps; ps = NULL;
	//ps = new Student[3]{...};
	
	ps = new Student[3];
	ps[0].show();
	delete[] ps; ps = NULL;

	cout << "--------------" << endl;
	//Student s3(); 相当于函数的声明
   	//s3.show();	
	ps = new Student();//无参构造
	//ps = new Student; 同上
	ps->show();
	delete ps; ps = NULL;
	return 0;
}
