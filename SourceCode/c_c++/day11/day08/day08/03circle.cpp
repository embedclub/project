//多继承的使用
#include <iostream>
#include <string>
using namespace std;

class Circle
{
private:
	int m_x;
	int m_y;//圆心的坐标
	int m_r;//半径
public:
	//有参的构造函数
	Circle(int x,int y,int r):m_x(x),m_y(y),m_r(r){}
	//返回圆的面积的函数
	double getArea(void)
	{
		return 3.14*m_r*m_r;
	}
};

class Table
{
private:
	int m_h; //桌子的高度
public:
	//有参的构造函数
	Table(int h):m_h(h){}
	//获取高度的成员函数
	int getHeight(void)
	{
		return m_h;
	}
};

class RoundTable : public Circle,public Table
{
private:
	string m_color;//颜色
public:
	//有参的构造函数
	RoundTable(int x,int y,int r,int h,const string& color):Circle(x,y,r),Table(h),m_color(color){}
	//提供一个获取颜色的函数
	string getColor(void)
	{
		return m_color;
	}
};

int main(void)
{
	RoundTable rt(1,1,3,4,"绿色");
	cout << "圆桌的桌面面积是：" << rt.getArea() << endl;
	cout << "圆桌的体积是：" << rt.getArea()*rt.getHeight() << endl;
	cout << "圆桌的颜色是：" << rt.getColor() << endl;
	return 0;
}
