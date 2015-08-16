//new 和 delete运算符的使用
#include <iostream>
using namespace std;

int main(void)
{
	int* pi = new int;
	*pi = 66;
	cout << "*pi = " << *pi << endl;//66
	delete pi; 
	pi = NULL;

	pi = new int(118);
	cout << "*pi = " << *pi << endl;//118
	delete pi;
	pi = NULL;

	cout << "-----------------" << endl;
	pi = new int[5];
	for(int i = 0; i < 5; i++)
	{
		pi[i] = i+1;
		cout << "pi[" << i << "] = " << pi[i] << endl;
	}
	delete[] pi;
	pi = NULL;

	cout << "-------------" << endl;
	pi = new int[5]{11,22,33,44,55};
	for(int i = 0; i < 5; i++)
	{
		cout << "pi[" << i << "] = " << pi[i] << endl;
	}
	delete[] pi;
	pi = NULL;

	//pi = new int[3][4];
	//int** ppi = new int[3][4];
	return 0;
}
