//常用的格式控制
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

int main(void)
{
	//设置10位有效数字的输出
	cout << cout.precision(10) << endl;
	//默认输出6位有效数字
	cout << "sqrt(2)  = " << sqrt(2) << endl;
	//使用带参格式控制符设置有效数字为8位
	cout << setprecision(8) << sqrt(2) << endl;
	cout.precision(2);
	//五舍六入法
	cout << 1.24 << ',' << 1.25 << ',' << 1.26 << endl;
	cout.precision(6);//恢复默认方式

	cout << "-------------------" << endl;
	cout << showbase/*显示进制的前缀*/ << hex/*十六进制*/ << 127 << endl;
	cout << showbase << oct/*八进制*/ << 127 << endl;
	cout << showbase << dec/*十进制*/ << 127 << endl;
	//不显示进制的前缀
	cout.unsetf(ios::showbase);
	cout << hex << 127 << endl;
	//显示进制的前缀
	cout.setf(ios::showbase);
	cout << hex << 127 << endl;
	cout << dec;//恢复十进制
	
	cout << "-----------------" << endl;
	//setw是一次性，只针对后面的输出有效
	cout << setw(10)/*输出10个字符的宽度,默认采用右对齐*/ << 1234 << endl;
	cout << setfill('#')/*空白位置用#填充*/ << setw(10) << 1234 << endl;
	cout << left/*左对齐*/ << setfill('@') << setw(10) << 1234 << endl;
	cout << right;//恢复右对齐

	cout << "---------------" << endl;
	cout << 12.00 << endl;
	cout << showpoint/*显示小数点后面的0*/ << 12.00 << endl;
	cout << sqrt(200) << endl;
	//采用科学计数法表示
	cout.setf(ios::scientific);
	cout << sqrt(200) << endl;
	//恢复到之前的小数表示法
	cout.setf(ios::fixed);
	cout << sqrt(200) << endl;
	
	cout << "----------------" << endl;
	ifstream ifs("white.txt");
	//不要跳过空白字符
	ifs.unsetf(ios::skipws);
	char c;
	while(ifs >> c)
	{
		cout << c;
	}
	
	//清除原来的状态标志
	ifs.clear();
	//跳过空白字符
	ifs.setf(ios::skipws);
	//读写位置回到文件的开头
	ifs.seekg(0,ios::beg);
	while(ifs >> c)
	{
		cout << c;
	}
	ifs.close();
	return 0;
}
