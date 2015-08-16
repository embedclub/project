//自定义Girl类
#include <iostream>
#include <string>
using namespace std;

class Girl
{
private:
	string m_name;//姓名
	int m_age;//年龄
	bool m_bf;//是否有男朋友
public:
	//带参的构造函数
	Girl(const string& name,int age,bool bf)
	{
		m_name = name;
		m_age = age;
		m_bf = bf;
	}
	//打印所有属性
	void show(void);
	/*
	{
		cout << "我是" << m_name << ",今年芳龄是" << m_age << "," << (m_bf?"已经名花有主了":"还没有男朋友") << endl;
	}*/
};

void Girl::show(void)
{
	cout << "我是" << m_name << ",今年芳龄是" << m_age << "," << (m_bf?"已经名花有主了":"还没有男朋友") << endl;
}

int main(void)
{
	Girl g1("小薇",20,true);
	g1.show();
	Girl g2("小芳",22,false);
	g2.show();
	return 0;
}
