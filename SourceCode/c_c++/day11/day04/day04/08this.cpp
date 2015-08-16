//this指针作为函数的参数实现对象间的交互
#include <iostream>
#include <string>
using namespace std;

//类的声明
class Student;

//自定义一个Teacher类
class Teacher
{
private:
	string m_answer;//存放答案
public:
	//授课的成员函数
	void educate(Student* ps);
	/*
	{
		//1.学生进行提问
		ps->ask("什么叫this指针？", this);
		//2.老师回答
		cout << m_answer << endl;
	}*/
	//回答问题的函数
	void replay(const string& answer)
	{
		m_answer = answer;
	}
};

class Student
{
public:
	void ask(const string& question,Teacher* pt)
	{
		cout << question << endl;
		pt->replay("this指针就是指向调用对象的指针");
	}
};
	
void Teacher::educate(Student* ps)
{
	//1.学生进行提问
	ps->ask("什么叫this指针？", this);
	//2.老师回答
	cout << m_answer << endl;
}

int main(void)
{
	Teacher t;
	Student s;
	t.educate(&s);
	return 0;
}
