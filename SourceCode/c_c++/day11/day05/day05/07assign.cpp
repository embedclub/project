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
	//自定义拷贝赋值运算符函数
	Student& operator=(const Student& s)
	{
		//避免自赋值
		if(this != &s)
		{
			//1.释放原来的内存空间
			delete[] m_pName; 
			m_pName = NULL;
			//2.申请新的内存空间
			m_pName = new char[strlen(s.m_pName)+1];
			//3.拷贝对应成员变量的值
			strcpy(m_pName,s.m_pName);
			m_age = s.m_age;
		}
		return *this;
	}
};

int main(void)
{
	Student s1("张飞",30);
	s1.show();
	
	Student s2(s1);
	s2.show();
	
	cout << "----------------" << endl;
	Student s3("关羽",35);
	s3.show();
	s3 = s2;//s3.operator=(s2);
	s3.show();
	
	cout << "---------------" << endl;
	int a = 10,b = 20,c = 30;
	(a = b) = c;
	cout << "a = " << a << endl;//30
	Student s4("赵云",28);
	s4.show();
	// s4.operator=(s3).operator=(s1);
	(s4 = s3) = s1;
	s4.show();
	return 0;
}
