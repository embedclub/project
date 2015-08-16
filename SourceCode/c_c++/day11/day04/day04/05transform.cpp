//支持自定义类型转换的构造函数
#include <iostream>
using namespace std;

//声明Point2d类
class Point2d;

//自定义三维坐标类
class Point3d
{
private:
	int m_x;
	int m_y;
	int m_z;
public:
	explicit Point3d(int x,int y = 0,int z = 0):m_x(x),m_y(y),m_z(z){}
	//打印函数
	void print(void)
	{
		cout << '(' << m_x << ',' << m_y << ',' << m_z << ')' << endl;
	}
	//带参的构造函数
	Point3d(const Point2d& pt2);//:m_x(pt2.m_x),m_y(pt2.m_y),m_z(300){}
};

//二维坐标类
class Point2d
{
private:
	int m_x;
	int m_y;
public:
	//有参的构造函数
	Point2d(int x,int y):m_x(x),m_y(y){}
	//打印
	void print(void)
	{
		cout << '(' << m_x << ',' << m_y << ')' << endl;
	}
	//声明Point3d为当前类的友元类
	friend class Point3d;
};

Point3d::Point3d(const Point2d& pt2):m_x(pt2.m_x),m_y(pt2.m_y),m_z(300){}

int main(void)
{
	Point3d pt3(1,2,3);
	pt3.print();
	Point2d pt2(100,200);
	pt2.print();
	
	cout << "-------------" << endl;
	// Point3d pt4(pt2);
	Point3d pt4 = pt2;
	pt4.print();

	//Point3d pt5 = 100; 错误
	Point3d pt5 = static_cast<Point3d>(100);
	pt5.print();
	return 0;
}
