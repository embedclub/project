//定位分配的使用
#include <iostream>
using namespace std;

int main(void)
{
	int* pi = new int(66);
	cout << "*pi = " << *pi << endl;
	delete pi;
	pi = NULL;

	short buf[2]; //4个字节
	int* q = new(buf) int(0x12345678);
	cout << "*q = " << showbase/*显示0x*/ << hex/*十六进制*/ << *q << endl;
	cout << buf[0] << ' ' << buf[1] << endl;
	cout << "q = " << q << ",buf = " << buf << endl;
	return 0;
}
