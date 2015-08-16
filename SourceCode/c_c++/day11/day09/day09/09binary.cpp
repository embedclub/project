//二进制I/O操作
#include <iostream>
#include <fstream>
using namespace std;

// a.out 源文件名 目标文件名
int main(int argc,char* argv[])
{
	if(argc < 3)
	{
		cout << "使用：" << argv[0] << " <源文件> <目标文件>" << endl;
		return -1;
	}

	//1.打开源文件和目标文件
	ifstream ifs(argv[1],ios::binary);
	if(!ifs)
	{
		cout << "打开源文件失败" << endl;
		return -1;
	}
	ofstream ofs(argv[2],ios::binary);
	if(!ofs)
	{
		cout << "打开目标文件失败" << endl;
	}

	//2.读取源文件内容写入到目标文件中
	char buf[1024];
	while(ifs.read(buf,sizeof(buf)))
	{
		ofs.write(buf,sizeof(buf));
	}
	//判断是否读取到文件尾部
	if(ifs.eof())
	{
		//读多少写多少
		ofs.write(buf,ifs.gcount()/*返回最后一次读取的字节数,也就是buf真正的数据大小*/);
	}
	else
	{
		cout << "读取错误" << endl;
		return -1;
	}

	//3.关闭源文件和目标文件
	ifs.close();
	ofs.close();
	return 0;
}
