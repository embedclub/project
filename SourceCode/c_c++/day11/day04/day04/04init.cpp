//初始化列表的必要性
#include <iostream>
using namespace std;

//int g_num = 100;
class User
{
private:
	const int m_id;// = 200//编号
	int& m_age;// = g_num;//年龄
public:
	User(int id,int age):m_id(id),m_age(age)
	{
		//m_id = id;错误,因为已经初始化完毕
		//m_age = age;
	}
	void show(void)
	{
		cout << "m_id = " << m_id << ",m_age = " << m_age << endl;
	}
};

int main(void)
{
	User u(101,20);
	u.show();
	return 0;
}
