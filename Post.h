#ifndef POST_H
#define POST_H
#include<vector>
#include "Comment.h"
#include<QString>

using namespace std;

class Post
{
private:
    vector<Comment* > C;//评论
    QString title;//帖子题目
    QString content;//帖子主体
    int num;//点赞数
    int is_top;//是否置顶（或者选择写一个置顶子类）
    QString user;//发帖人姓名
    QString id;
public:
    Post();
    void Like();//点赞
    void set_post(QString,QString,QString,QString);
    QString get_name();
    QString get_title();
    QString get_content();
    QString get_id();
    int get_top();
    void set_num(int);
    void set_top();
    void add(Comment *a);
    void set_notop();
    int get_num();//获取点赞数
    vector <Comment *> get_comment();
    void set_comment(vector <Comment *>);
};

#endif // POST_H
