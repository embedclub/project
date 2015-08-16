//文件的读写位置调整
#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	//打开文件，输入和输出
	fstream fs("pos.txt",ios::in|ios::out);
	if(!fs)
	{
		cout << "打开文件失败" << endl;
		return -1;
	}

	//按照格式向文件中写入数据
	fs << 1234 << " " << 56.78 << " " << "apples" << '\n';
	cout << "文件当前的读写位置是：" << fs.tellg() << endl;
	cout << "文件当前的读写位置是：" << fs.tellp() << endl;

	//改变文件的读写位置
	fs.seekg(0,ios::beg);
	cout << "读写位置是：" << fs.tellg() << endl;
	cout << "读写位置是：" << fs.tellp() <<endl;

	fs << 5678;//覆盖1234
	
	fs.seekp(1,ios::cur);
	fs << 12.34;//覆盖56.78
	
	fs.seekp(-7,ios::end);
	fs << "APPLES\n";//覆盖apples\n

	//关闭文件
	fs.close();
	return 0;
}
