//函数重载的初识
#include <iostream>
using namespace std;

int foo(int i){}
int foo(void){} //构成重载
int foo(int i,int j){} //构成重载
//不能构成重载,与形参变量名无关
//int foo(int j,int i){}
//不能构成重载，与返回值类型无关
//void foo(int i,int j){}
int foo(int i,double d){}//构成重载
int foo(double d,int i){}//构成重载

struct Student
{
	void show(void){}
};
struct Teacher
{
	void show(int){}
};//不能构成重载

int main(void)
{
	return 0;
}
