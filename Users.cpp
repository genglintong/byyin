#include "Users.h"

Users::Users()
{

}

void Users::change_password(QString s){
    password=s;
}

void Users::change_username(QString s){
    user_name=s;
}

void Users::choose_board(int i){
    board = i;
}

QString Users::get_password(){
    return password;
}

QString Users::get_username(){
    return user_name;
}

QString Users::get_id(){
    return id;
}

void Users::view_post(int i){
    //弹出帖子窗口
}
void Users::Init(){
    id="";
    user_name="";
    password="";
    is_online=0;
    board=0;
}
void Users::set_id(QString s){
    id=s;
}

