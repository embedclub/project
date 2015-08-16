//格式化输入输出的使用
#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	//cout << "hello";
	//打开文件,不存在则创建/覆盖
	ofstream ofs("a.txt");
	//按照格式向文件中写入数据
	ofs << 1234 << " " << 56.78 << " " << "apples" << '\n';
	//关闭文件
	ofs.close();

	//表示以追加的方式打开文件
	ofstream ofs2("a.txt",ios::app);
	ofs2 << "append_a_line\n";
	ofs2.close();
	
	//按照格式从文件中读取数据
	ifstream ifs("a.txt");
	int n = 0;
	double d = 0;
	string str1,str2;
	ifs >> n >> d >> str1 >> str2;
	cout << "n = " << n << ",d = " << d << ",str1 = " << str1 << ",str2 = " << str2 << endl;
	ifs.close();

	ifstream ifs2("b.txt");
	if(!ifs2)
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	ifs2.close();
	return 0;
}
