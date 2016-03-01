//数据对象的存储
#ifndef DAO_H_
#define DAO_H_
#include "bank.h"
//生成不重复的帐号
int generator_id();
//将新帐号添加到文件中,为开户服务
int createUser(struct Account acc);
//销户功能
int destroyUser(struct Account acc);
//存钱功能
int saveMoney(struct Account acc,struct Account *p);
//取钱功能
int getMoney(struct Account acc,struct Account *p);
//查询余额功能
int checkMoney(struct Account acc,struct Account *p);
//转账功能
int moveMoney(struct Account acc1,struct Account acc2,struct Account *p);
#endif
