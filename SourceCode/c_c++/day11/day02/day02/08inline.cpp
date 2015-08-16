//内联函数的使用
#include <iostream>
using namespace std;

/*内联函数，可以进行替换*/
inline void fn(void){}

int main(void)
{
	fn();
	return 0;
}
