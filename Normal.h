#ifndef NORMAL_H
#define NORMAL_H
#include "Users.h"

using namespace std;

class Normal : public Users{
private:
    int level;//等级（随时间与发帖增长）
    int is_Master;
public:
    int board;
    Normal();
    void write_post(QString ,QString ,QString);//写帖子
    void write_comment(QString ,QString );//写评论
    void delete_comment();//删除评论
    int get_level();
    void set_level(int);
    virtual void view_yourself();//函数重写
    virtual void Init();
    int get_master();
    void change_master(int i);
    virtual void delete_post(int )
    {
    }//纯虚
    virtual int is_board(){
        return board;
    }
    virtual void set_board(int i){
        board=i;
    }
};

class Master : public Normal{
private:
    //int board;//自己管理的版块
public:
    virtual void delete_post(int );//删除帖子
    virtual int is_board();
    virtual void set_board(int i);
};

#endif // NORMAL_H
