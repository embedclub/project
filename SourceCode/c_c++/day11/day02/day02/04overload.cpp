//重载的原理
#include <iostream>
using namespace std;

void show(int i,int j)
{
	cout << "在show(1)函数中,i = " << i << ",j = " << j << endl; 
}
void show(int i,double d)
{
	cout << "在show(2)函数中,i = " << i << ",d = " << d << endl;
}

int main(void)
{
	show(66,118);
	show(250,3.14);
	return 0;
}
