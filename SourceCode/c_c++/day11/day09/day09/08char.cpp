//按照字符进行读写
#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	//向文件中写入字符
	ofstream ofs("put.txt");
	if(!ofs)
	{
		cout << "打开写入文件失败" << endl;
		return -1;
	}
	
	for(char c = ' '; c <= '~'; c++)
	{
		ofs.put(c);
	}

	//关闭文件
	ofs.close();
	
	//打开文件
	ifstream ifs("put.txt");
	if(!ifs)
	{
		cout << "打开读取文件失败" << endl;
		return -1;
	}
	char c;
	//表示读取成功
	while((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	cout << endl;
	//判断是否出错
	if(!ifs.eof())
	{
		cout << "读取错误了" << endl;
		return -1;
	}
	ifs.close();
	//关闭文件
	return 0;
}
