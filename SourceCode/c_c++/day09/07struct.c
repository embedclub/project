/*
    结构体演示
*/
#include <stdio.h>
#include <string.h>
struct phone {
    char model[10];   //型号
    int price;        //价格
    int quantity;     //数量
};
//typedef struct phone phone;
//typedef struct /*phone*/ {
//    char model[10];
//    int price;
//    int quantity;
//} phone;
//#define    phone          struct phone   错误
int main() {
    struct phone iphone6;
    //phone iphone5;
    struct phone *p_phone = NULL;  //结构体指针
    strcpy(iphone6.model, "IPhone 6");
    iphone6.price = 5000;
    iphone6.quantity = 100;
    p_phone = &iphone6;
    printf("型号是%s\n", iphone6.model);
    printf("型号是%s\n", p_phone->model);
    printf("价格是%d元\n", iphone6.price);
    printf("价格是%d元\n", p_phone->price);
    printf("数量是%d\n", iphone6.quantity);
    printf("数量是%d\n", p_phone->quantity);
    return 0;
}





