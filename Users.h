#ifndef USERS_H
#define USERS_H
#include<QString>
#include <vector>

using namespace std;

class Users
{
private:
    QString id;//用户id
    QString user_name;//用户名
    QString password;//密码
    int is_online;//是否在线..
    int board;//当前版面
public:
    Users();
    void choose_board(int i);//选择版面
    virtual void view_yourself()=0;//查看自己信息   纯虚函数
    void view_post(int);//查看帖子
    void change_username(QString s);//修改用户名
    void change_password(QString s);//修改密码
    //void change_id(QString s);
    QString get_username();
    QString get_password();
    virtual void Init();//虚函数
    QString get_id();
    void set_id(QString);
};

#endif // USERS_H
