//继承的初识
#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string m_name;//姓名
	int m_age;//年龄
public:
	//有参的构造函数
	Person(const string& name,int age):m_name(name),m_age(age)
	{
		cout << "我是" << m_name << "，今年" << m_age << "岁了" << endl;
	}
	//吃饭的行为
	void eat(const string& food)
	{
		cout << food << "真好吃" << endl;
	}

protected:
	//获取姓名的成员函数
	string getName(void)
	{
		return m_name;
	}
};

//表示以公有方式继承自Person类
class Student : public Person
{
private:
	int m_id;//学号
public:
	Student(const string& name,int age,int id):Person(name,age),m_id(id)
	{
		cout << "我是学生，我的学号是：" << m_id << endl;
	}
	//学习的行为
	void learn(const string& lesson)
	{
		cout << "正在学习" << lesson << endl;
		// m_id的数值可能不靠普
		//cout << "学号是：" << m_id << endl;
	}
	//打印的函数
	void show(void)
	{
		// error 不能访问父类中的私有成员
		//cout << "m_name = " << m_name << endl;
		cout << "获取到的姓名是：" << getName() << endl;
	}
	//在子类中定义吃饭的行为
	//void eat(const string& food)
	//int eat(const string& food)
	int eat(void)
	{
		cout << "在子类eat函数中" << endl;// << food << "真好吃" << endl;
	}
};

int main(void)
{
	Student s("张飞",30,1001);
	s.learn("C++");
	s.eat("拉面");

	/*cout << "------------------" << endl;
	//父类指针指向子类对象
	Person* p = new Student("关羽",35,1002);
	p->eat("包子");
	// p是Person类型的，Person中无learn函数
	//p->learn("JAVA");error

	cout << "----------------" << endl;
	Student* ps = static_cast<Student*>(new Person("赵云",28));
	ps->eat("麻辣香锅");
	ps->learn("嵌入式");
	
	cout << "--------------" << endl;
	s.show();
	// 保护成员不能在类的外部进行访问
	//cout << "使用保护成员函数获取的数据是：" << s.getName() << endl;
	*/
	return 0;
}
