//内联函数的使用
#include <iostream>
using namespace std;

inline int square(int x)
{
	return x*x;
}

int main(void)
{
	for(int i = 1; i < 100000; i++)
	{
		square(i);
	}
	return 0;
}
