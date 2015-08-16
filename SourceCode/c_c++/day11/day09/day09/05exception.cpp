//自定义异常类型以及处理
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class MyException
{
private:
	string m_file;//发生异常的文件
	int m_line;//发生异常行号
	string m_msg;//发生的异常信息
public:
	MyException(const string& file,int line,const string& msg):m_file(file),m_line(line),m_msg(msg){}
	friend ostream& operator<<(ostream& os,const MyException& me)
	{
		return os << me.m_file << ':' << me.m_line << '-' << me.m_msg;
	}
};

class FileException : public MyException
{
public:
	FileException(const string& file,int line,const string& msg):MyException(file,line,msg){}
};

class MemException : public MyException
{
public:
	MemException(const string& file,int line,const string& msg):MyException(file,line,msg){}
};

class MException : public exception
{
public:
	//覆盖exception中的虚函数
	const char* what() const throw()
	{
		return "我错了";
	}
};

void config(int n) throw(FileException)
{
	if(10 == n)
	{
		throw FileException(__FILE__,__LINE__,"网络配置文件不存在");
	}
	else if(20 == n)
	{
		throw MemException(__FILE__,__LINE__,"内存不够分配");
	}
	else if(30 == n)
	{
		throw MException();
	}
	else
	{
		throw "good good study,day day up";
	}
}


int main(void)
{
	try
	{
		config(30);
	}
	catch(FileException& ex)
	{
		cout << ex << endl;
	}
	catch(MemException& ex)
	{
		cout << ex << endl;
	}
	catch(exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch(...)
	{
		cout << "收到未知的异常" << endl;
	}
	return 0;
}
