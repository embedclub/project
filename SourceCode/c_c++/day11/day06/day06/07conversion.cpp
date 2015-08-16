//类型转换运算符函数
#include <iostream>
using namespace std;

class Point2d;

class Point3d
{
private:
	int m_x;
	int m_y;
	int m_z;
public:
	//有参的构造函数
	Point3d(int x,int y,int z):m_x(x),m_y(y),m_z(z){}
	//支持输出运算符重载
	friend ostream& operator<<(ostream& os,const Point3d& pt3)
	{
		return os << '(' << pt3.m_x << ',' << pt3.m_y << ',' << pt3.m_z << ')';
	}
	//支持自定义类型转换的构造函数
	Point3d(const Point2d& pt2);//:m_x(pt2.m_x),m_y(pt2.m_y),m_z(30){}
};

class Point2d
{
private:
	int m_x;
	int m_y;
public:
	Point2d(int x,int y):m_x(x),m_y(y){}
	//支持输出运算符重载
	friend ostream& operator<<(ostream& os,const Point2d& pt2)
	{
		return os << '(' << pt2.m_x << ',' << pt2.m_y << ')';
	}
	//类型转换运算符函数
	operator Point3d(void)
	{
		cout << "类型转换运算符函数" << endl;
		return Point3d(m_x,m_y,30);
	}
	friend class Point3d;
};
	
Point3d::Point3d(const Point2d& pt2):m_x(pt2.m_x),m_y(pt2.m_y),m_z(30){}

int main(void)
{
	Point3d pt3(1,2,3);
	cout << "pt3 = " << pt3 << endl;
	Point2d pt2(10,20);
	cout << "pt2 = " << pt2 << endl;
	
	// pt2.operator Point3d();
	//pt3 = pt2; 运算符转换函数
	// 优先选择调用构造函数
	//pt3 = static_cast<Point3d>(pt2);
	cout << "pt3 = " << pt3 << endl;
	return 0;
}
