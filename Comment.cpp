#include "Comment.h"

Comment::Comment()
{

}

void Comment::set_comment(QString id1, QString id2, QString s){
    from_user=id1;
    to_user=id2;
    content=s;
}

QString Comment::get_content(){
    return content;
}

QString Comment::get_from(){
    return from_user;
}

QString Comment::get_to(){
    return to_user;
}
