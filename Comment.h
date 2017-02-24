#ifndef COMMENT_H
#define COMMENT_H
#include "Users.h"
#include <QString>

using namespace std;

class Comment
{
private:
    QString from_user;//发送用户ID
    QString to_user;//主贴用户ID
    QString content;//评论内容
public:
    Comment();
    void set_comment(QString,QString,QString);
    QString get_from();
    QString get_to();
    QString get_content();
};

#endif // COMMENT_H
