#ifndef ADMIN_H
#define ADMIN_H
#include "Users.h"

using namespace std;

class Admin : public Users{
public:
    Admin();
    void appoint_master(int i);//任命版主
    void delete_master(int i);//撤销版主
    virtual void view_yourself();//函数重写
};

#endif // ADMIN_H
