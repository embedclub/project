//new 和 delete 操作符的重载
#include <iostream>
#include <cstdlib>
using namespace std;

class A
{
// 对于一个空类 sizeof结果是1，一旦拥有成员变量则遵循对齐 补齐 原则
private:
	int m_n;
public:
	A(void)
	{
		cout << "A被构造了" << endl;
	}
	~A(void)
	{
		cout << "析构Ａ" << endl;
	}
	//支持new运算符的重载
	static void* operator new(size_t size)
	{
		void* p = malloc(size);
		cout << "自定义New中：p = " << p << ",size = " << size << endl;
		return p;
	}
	//重载delete运算符函数
	static void operator delete(void* p)
	{
		cout << "自定义Delete中：p = " << p << endl;
		free(p);
		p = NULL;
	}

	static void* operator new[] (size_t size)
	{
		void* p = malloc(size);
		cout << "自定义new[]中：p = " << p << ",size = " << size << endl;
		return p;
	}
	static void operator delete[](void* p)
	{
		cout << "自定义delete[]中：p = " << p << endl;
		free(p);
		p = NULL;
	}
};

class B
{
public:
	B(void)
	{
		cout << "B被构造了" << endl;
	}
	~B(void)
	{
		cout << "析构Ｂ" << endl;
	}
};

int main(void)
{
	//分两步：
	//1.使用malloc分配内存
	//2.调用构造函数进行初始化
	A* pa = new A;
	delete pa;
	pa = NULL;

	cout << "---------------" << endl;
	pa = new A[3];
	//额外多出来的4个字节主要存储元素的个数等附加信息
	//A* pa2 = pa;
	//cout << "额外多出来的内存空间中存储的数据是：" << *((int*)pa-1) << endl;
	delete[] pa;
	pa = NULL;

	cout << "------------------" << endl;
	B* pb = new B;
	delete pb;
	pb = NULL;
	return 0;
}
