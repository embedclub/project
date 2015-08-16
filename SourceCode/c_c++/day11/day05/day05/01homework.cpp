//自定义Clock类,实现时间的打印
#include <iostream>
#include <ctime>
#include <iomanip>
#include <unistd.h>
using namespace std;

class Clock
{
private:
	int m_hour;
	int m_min;
	int m_sec;
public:
	//无参的构造函数初始化成员变量
	Clock(void)
	{
		time_t t = time(0);
		struct tm* pt = localtime(&t);
		m_hour = pt->tm_hour;
		m_min = pt->tm_min;
		m_sec = pt->tm_sec;
	}
	//每隔一秒时间加1
	void tick(void)
	{
		sleep(1);
		if(60 == ++m_sec)
		{
			m_sec = 0;
			if(60 == ++m_min)
			{
				m_min = 0;
				if(24 == ++m_hour)
				{
					m_hour = 0;
				}
			}
		}
	}
	//打印时间的函数
	void show(void)
	{
		cout << '\r'/*回车不换行*/ << setfill('0')/*空位填0*/ << setw(2)/*输出两个字符的宽度,一次性*/ << m_hour << ':' << setw(2) << m_min << ':' << setw(2) << m_sec << flush/*刷新*/;
	}
	//提供run函数让时间动起来
	void run(void)
	{
		while(1)
		{
			tick();
			show();
		}
	}
};

int main(void)
{
	Clock c;
	c.run();
	return 0;
}
