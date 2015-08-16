//下标操作符的重载
#include <iostream>
using namespace std;

class IntArray
{
private:
	int* m_arr;
	int m_len;
	int m_pos;
public:
	IntArray(int len):m_arr(new int[m_len = len]),m_pos(0){}
	~IntArray(void)
	{
		delete[] m_arr;
		m_arr = NULL;
	}
	bool push(int num)
	{
		if(m_pos == m_len)
		{
			return false;
		}
		m_arr[m_pos++] = num;
		return true;
	}
	void print(void)
	{
		cout << "数组中的元素有：";
		for(int i = 0; i < m_pos; i++)
		{
			cout << m_arr[i] << ' ';
		}
		cout << endl;
	}
	//支持[]操作符重载
	int operator[](int i)
	{
		return m_arr[i];
	}
};

int main(void)
{
	IntArray ia(5);
	for(int i = 0; i < 5; i++)
	{
		ia.push(i);
	}
	ia.print();

	cout << "---------------" << endl;
	for(int i = 0; i < 5; i++)
	{
		// ia.operator[](i);
		cout << ia[i] << ' ';
	}
	cout << endl;
	return 0;
}
