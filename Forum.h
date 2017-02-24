#ifndef FORUM_H
#define FORUM_H
#include<bits\stdc++.h>
#include "Board.h"
#include "Users.h"
#include "Normal.h"
#include "Admin.h"
#include <iostream>

using namespace std;

class Forum
{
public:
    vector<Board* > board;//板块
    vector<Admin *> admin;
    vector<Normal *> normal;
    Forum();
    friend ostream & operator << (ostream & out,Board *b);
    friend istream & operator >> (istream & in,Board *b);
    friend ostream & operator << (ostream & out,Admin *a);
    friend istream & operator >> (istream & in,Admin *a);
    friend ostream & operator << (ostream & out,Normal *n);
    friend istream & operator >> (istream & in,Normal *n);
    void Init();//论坛初始化
    int login_in(QString ,QString,int);
    void login_out();
};

#endif // FORUM_H
