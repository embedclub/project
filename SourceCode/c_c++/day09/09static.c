/*
    静态变量演示
*/
#include <stdio.h>
void func() {
    static int num = 0;
    printf("&num是%p\n", &num);
    printf("num是%d\n", num);
    num = 3;

}
void func2() {
	int num = 3;
	printf("&num is %p\n", &num);
	printf("num is %d\n", num);
}
void func3() {
	int num = 9;
	printf("&num is %p\n", &num);
	printf("num is %d\n", num);
}
void func1() {
    int num = 0;
    func();
	func2();
	func3();
}
int main() {
    func();
    func1();
    return 0;
}
