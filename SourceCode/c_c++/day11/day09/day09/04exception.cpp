//异常的使用
#include <iostream>
#include <cstdio>
using namespace std;

//配置环境的函数
int config(void)
{
	FILE* fp = fopen("a.dat","r");
	if(NULL == fp)
	{
		//return -1;
		cout << "在throw之前" << endl;
		throw 100;
		cout << "在throw之后" << endl;
	}
	//进行相关环境的配置
	// ...
	return 0;
}

//初始化
int init(void)
{
	if(-1 == config())
	{
		return -1;
	}
	// ...
	return 0;
}

int main(void)
{
	/*if(-1 == init())
	{
		cout << "配置失败" << endl;
		return -1;
	}
	cout << "配置成功" << endl;*/
	//try
	//{
		cout << "调用init之前" << endl;
		init();
		cout << "调用init之后" << endl;
	/*}
	catch(int ex)
	{
		if(100 == ex)
		{
			cout << "打开配置文件失败" << endl;
			return -1;
		}
	}*/
	return 0;
}
