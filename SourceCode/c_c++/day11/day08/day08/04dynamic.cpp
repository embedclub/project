//多态的初识
#include <iostream>
using namespace std;

//将矩形类和圆形类的共性提取出来
class Shape
{
protected:
	int m_x;
	int m_y;//两个坐标
public:
	//有参的构造函数
	Shape(int x,int y):m_x(x),m_y(y){}
	//绘制图形的函数
	virtual void draw(void)
	{
		cout << "绘制图形(" << m_x << ',' << m_y << ')' << endl;
	}
};

class Rect : public Shape
{
private:
	//int m_x;
	//int m_y;//起始坐标
	int m_h;//高度
	int m_w;//宽度
public:
	//有参的构造函数
	Rect(int x,int y,int h,int w):Shape(x,y),m_h(h),m_w(w){}
	//提供一个绘制矩形的函数
	void draw(void)
	{
		cout << "绘制矩形(" << m_x << ',' << m_y << ',' << m_h << ',' << m_w << ')' << endl;
	}
	//与本类中的draw构成重载,与父类中的draw函数产生名字隐藏
	void draw(int i)
	{
		cout << "Rect类中的draw函数" << endl;
	}
};

class Circle : public Shape
{
private:
	//int m_x;
	//int m_y;
	int m_r;//半径
public:
	//有参的构造函数
	Circle(int x,int y,int r):Shape(x,y),m_r(r){}
	//绘制圆形的函数
	void draw(void)
	{
		cout << "绘制圆形(" << m_x << ',' << m_y << ',' << m_r << ')' << endl;
	}
};

//自定义函数 既能绘制矩形又能绘制圆形
void bigDraw(Shape* shapes[5],int n)
{
	for(int i = 0; i < n; i++)
	{
		shapes[i]->draw();
	}
}

int main(void)
{
	/*
	Rect rt(1,1,2,3);
	rt.draw();
	Circle cc(4,5,6);
	cc.draw();
	*/
	Shape* shapes[5];//指针数组
	shapes[0] = new Rect(1,2,3,4);
	shapes[1] = new Circle(5,6,7);
	shapes[2] = new Circle(8,9,10);
	shapes[3] = new Rect(11,12,13,14);
	shapes[4] = new Circle(15,16,17);
	bigDraw(shapes,5);
	
	cout << "---------------" << endl;
	Circle c(1,2,3);
	Shape& rs = c;
	rs.draw();

	cout << "---------------" << endl;
	Shape s = c;
	s.draw();
	return 0;
}
