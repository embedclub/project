//使用malloc/free管理动态内存
#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
	int* p = (int*)malloc(sizeof(int));
	*p = 66;
	cout << "*p = " << *p << endl;
	free(p);
	p = NULL;

	p = (int*)malloc(10*sizeof(int));
	for(int i = 0; i < 10; i++)
	{
		p[i] = i+1;
		cout << "p[" << i << "] = " << p[i] << endl;
	}
	free(p);
	p = NULL;
	return 0;
}
