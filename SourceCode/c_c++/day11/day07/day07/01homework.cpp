//整型数组类的实现
#include <iostream>
using namespace std;

class IntArray
{
private:
	int* m_arr;//记录内存的首地址
	int m_len; //记录内存的大小
	int m_pos; //记录数组的下标
public:
	//提供有参的构造函数
	IntArray(int len):m_arr(new int[m_len = len]),m_pos(0){}
	//析构函数
	~IntArray(void)
	{
		delete[] m_arr;
		m_arr = NULL;
	}
	//向数组的尾部插入一个元素
	bool push(int num)
	{
		if(m_pos == m_len)
		{
			return false;
		}
		m_arr[m_pos++] = num;
		//m_pos++;
		return true;
	}
	//从数组的尾部弹出一个元素
	bool pop(int& num)
	{
		if(0 == m_pos)
		{
			return false;
		}
		num = m_arr[--m_pos];
		return true;
	}
	//根据下标获取一个元素值
	bool get(int pos,int& num)
	{
		if(pos < 0 || pos >= m_pos)
		{
			return false;
		}
		num = m_arr[pos];
		return true;
	}
	//根据下标去设置一个元素值
	bool set(int pos,int num)
	{
		if(pos < 0 || pos >= m_pos)
		{
			return false;
		}
		m_arr[pos] = num;
		return true;
	}
	//打印数组中的所有元素
	void print(void)
	{
		cout << "数组中的元素有：";
		for(int i = 0; i < m_pos; i++)
		{
			cout << m_arr[i] << ' ';
		}
		cout << endl;
	}
};

int main(void)
{
	IntArray ia(10);
	for(int i = 0; i < 10; i++)
	{
		ia.push(i);
	}
	ia.print();
	cout << boolalpha << ia.push(10) << endl;

	cout << "--------------" << endl;
	ia.set(0,100);
	ia.set(1,101);
	ia.set(2,102);
	int num = 0;
	ia.get(0,num);
	cout << "num = " << num << endl;
	ia.get(1,num);
	cout << "num = " << num << endl;
	ia.print();
	
	cout << "-------------" << endl;
	cout << "弹出的元素依次是：";
	for(int i = 0; i < 10; i++)
	{
		ia.pop(num);
		cout << num << ' ';
	}
	cout << endl;
	cout << ia.pop(num) << endl;
	return 0;
}
