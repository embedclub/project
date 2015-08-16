//new和delete使用
#include <iostream>
using namespace std;

int main(void)
{
	int (*pi)[4] = new int[3][4];
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			pi[i][j] = i+1;
			cout << "pi[" << i << "][" << j << "] = " << pi[i][j] << endl;
		}
	}
	delete[] pi;
	pi = NULL;

	cout << "----------------" << endl;
	pi = new int[3][4]{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			cout << "pi[" << i << "][" << j << "] = " << pi[i][j] << endl;
		}
	}
	delete[] pi;
	pi = NULL;

	cout << "---------------" << endl;
	int (*qi)[3][4] = new int[2][3][4];
	delete[] qi;
	qi = NULL;
	return 0;
}
