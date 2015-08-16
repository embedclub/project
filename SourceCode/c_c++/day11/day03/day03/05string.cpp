//string类型的使用
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	//char* ps = "hello";
	string s = "hello";
	cout << "s = " << s << endl;
	//用"world"字符串初始化s2
	string s2("world");
	cout << "s2 = " << s2 << endl;

	string s3 = s;
	cout << "s3 = " << s3 << endl;
	s3 = s2;
	cout << "s3 = " << s3 << endl;
	
	s = s + s2;
	cout << "s = " << s << endl;
	s2 += s3;
	cout << "s2 = " << s2 << endl;
	
	if(s > s3)
	{
		cout << "字符串" << s << "比较大" << endl;
	}
	cout << "s[0] = " << s[0] << endl;
	cout << "s[1] = " << s[1] << endl;

	// c_str()函数的返回值类型 const char*
	cout << "转换出来的C风格字符串是：" << s.c_str() << endl;
	// 计算的长度不包括 '\0'
	cout << "字符串s的长度是：" << s.length() << endl;
	char* ps = "GoodMorning";
	s = ps;
	cout << "s = " << s << endl;
	return 0;
}
