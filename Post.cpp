#include "Post.h"

Post::Post()
{

}

void Post::set_post(QString t, QString c,QString i,QString n){
    this->num=0;
    this->is_top=0;
    this->title=t;
    this->content=c;
    this->id=i;
    this->user=n;
}

void Post::set_num(int i){
    num=i;
}

void Post::set_top(){
    is_top=1;
}

void Post::set_notop(){
    is_top=0;
}

QString Post::get_title(){
    return title;
}

QString Post::get_name(){
    return user;
}

QString Post::get_content(){
    return this->content;
}

void Post::Like(){
    this->num++;
}

int Post::get_num(){
    return num;
}

int Post::get_top(){
    return is_top;
}

vector <Comment *> Post::get_comment(){
    return C;
}

void Post::set_comment(vector<Comment *> s){
    C=s;
}

QString Post::get_id(){
    return id;
}

void Post::add(Comment * a){
    this->C.push_back(a);
}
