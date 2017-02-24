#include "Normal.h"
#include "Users.h"
#include "Comment.h"
#include "Post.h"
#include "globle.h"
#include <QDebug>

using namespace std;

Normal::Normal()
{

}

void Normal::delete_comment(){
    if(1){//判断评论发送人与本人是否相同（使用id)

    }
}

void Normal::Init(){
    is_Master=0;
    level=0;
}

int Normal::get_master(){
    return is_Master;
}

void Normal::change_master(int i){
    is_Master=i;
}

void Normal::set_level(int i){
    level=i;
}

void Normal::write_comment(QString to,QString c){
    Comment *new_comment=new Comment;
    new_comment->set_comment(this->get_id(),to,c);
    f.board[now_board-1]->P[now_post]->add(new_comment);
    //应改为帖子发起人id
    //将评论添加到帖子评论容器
    //刷新
}
void Normal::view_yourself(){
    //弹出窗口.显示自己信息
}

void Normal::write_post(QString s1,QString s2,QString i){
    Post *new_post=new Post;
    new_post->set_post(s1,s2,i,this->get_username());
    f.board[now_board-1]->P.push_back(new_post);
    qDebug()<<"s";
    level=level+1;
}
int Normal::get_level(){
    return level;
}

void Master::delete_post(int i){

    f.board[now_board-1]->P.erase(f.board[now_board-1]->P.begin()+i);
    qDebug()<<f.board[now_board-1]->P.size();
}
int Master::is_board(){
    return board;
}
void Master::set_board(int i){
    board=i;
}
