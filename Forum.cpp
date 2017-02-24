#include "Forum.h"
#include "Admin.h"
#include "Users.h"
#include "Normal.h"
#include <QDebug>
#include "globle.h"
#include<bits\stdc++.h>
#include "wrong.h"
#include <exception>

using namespace std;

Forum::Forum()
{


}


ostream & operator << (ostream & out,Comment *c){
    QString from=c->get_from();
    QString to=c->get_to();
    QString content=c->get_content();

    out<<"#"<<endl;
    out<<content.toStdString()<<" "<<from.toStdString()<<" "<<to.toStdString()<<endl;

}

ostream & operator << (ostream & out,Post *p){
    vector <Comment *> c=p->get_comment();
    QString user,id,title,content;
    int num,is_top;
    int t=c.size();
    out<<"##"<<endl;
    user=p->get_name();
    id=p->get_id();
    title=p->get_title();
    content=p->get_content();
    num=p->get_num();
    is_top=p->get_top();
    out<<title.toStdString()<<" "
       <<content.toStdString()<<" "
      <<user.toStdString()<<" "
     <<id.toStdString()<<" "
    <<num<<" "<<is_top<<" "<<t<<endl;

    for(int i=0;i<t;i++){
        out<<c[i];
    }

    return out;
}
ostream & operator << (ostream & out,Board *b){
    int t=b->P.size();
    Post *p;

    QString name=b->get_name();
    out<<"###"<<endl;
    out<<name.toStdString()<<" "<<t<<endl;
    qDebug()<<name;

    for(int i=0;i<t;i++){
        p=b->P[i];
        out<<p;
    }
    return out;
}

istream & operator >> (istream & in,Comment *c){
    string from,to,content,s;
    //in>>s;
    in>>to>>from>>content;
    c->set_comment(QString::fromStdString(from),QString::fromStdString(to),QString::fromStdString(content));

    return in;
}

istream & operator >> (istream & in,Post *p){
    string title,content,user,id;
    string s;
    int num,top,t;
    //in>>s;
    in>>title>>content>>user>>id>>num>>top>>t;

    p->set_post(QString::fromStdString(title),QString::fromStdString(content),QString::fromStdString(id),QString::fromStdString(user));
    p->set_num(num);
    if(top>0){
        p->set_top();
    }


    vector <Comment *> comment;

    //in>>s;
    for(int i=0;i<t;i++){
        Comment *c=new Comment;
        in>>s;
        in>>c;
        comment.push_back(c);
        //in>>s;
    }
    p->set_comment(comment);

    return in;
}

istream & operator >> (istream & in,Board *b){
    string name,s;
    int t;
    //in>>s;
    in>>name>>t;
    qDebug()<<"uu"<<QString::fromStdString(name)<<t;
    b->Init(QString::fromStdString(name));

    //in>>s;

    for(int i=0;i<t;i++){
        Post *p=new Post;
        in>>s;
        in>>p;
        qDebug()<<p->get_title();
        b->P.push_back(p);
        //in>>s;
    }

    return in;
}



ostream & operator << (ostream & out,Admin *a){
    QString user_name=a->get_username();
    QString password=a->get_password();
    QString id=a->get_id();
    out<<user_name.toStdString()<<" "<<password.toStdString()<<" "<<id.toStdString()<<endl;
    return out;
}

istream & operator >> (istream & in,Admin *a){
    string user_name,password,id;

    in>>user_name>>password>>id;
    qDebug()<<QString::fromStdString(user_name);
    a->change_password(QString::fromStdString(password));
    a->change_username(QString::fromStdString(user_name));
    a->set_id(QString::fromStdString(id));

    return in;
}

ostream & operator << (ostream & out,Normal *n){
    QString user_name=n->get_username();
    QString password=n->get_password();
    QString id=n->get_id();

    out<<user_name.toStdString()<<" "<<password.toStdString()<<" "<<id.toStdString()<<" "<<n->get_level()<<" "<<n->get_master()<<" "<<n->is_board()<<endl;
    qDebug()<<user_name;
    return out;
}

istream & operator >> (istream & in,Normal *n){
    string user_name,password,id;
    int is_master;
    int level;
    int board;

    in>>user_name>>password>>id>>level>>is_master>>board;
    qDebug()<<"&&"<<board;

    //if(is_master==1){
      //  n=new Master;
    //}

    n->change_username(QString::fromStdString(user_name));
    n->change_password(QString::fromStdString(password));
    n->set_id(QString::fromStdString(id));
    n->change_master(is_master);
    n->set_level(level);
    n->set_board(board);

    qDebug()<<board<<"&&"<<n->is_board();
}

void Forum::Init(){
    //qDebug()<<"in init()";
   /* Board *board_a,*board_b,*board_c,*board_d;//初始四个板块
    board_a=new Board;
    board_b=new Board;
    board_c=new Board;
    board_d=new Board;
    board_a->Init("校园生活");
    board_b->Init("谈天说地");
    board_c->Init("学术科技");
    board_d->Init("休闲娱乐");
    //Post *a=new Post;
    //a->set_post("helloword","lll","aaa","aaa");
    //board_a->P.push_back(a);
    board.push_back(board_a);
    board.push_back(board_b);
    board.push_back(board_c);
    board.push_back(board_d);
    //qDebug()<<"in Init()"<<this->board.empty();
*/
    admin.clear();
    ifstream in;
    try{
       in.open("admin.txt");
    }
    catch(exception &e){
        wrong *w =new wrong;
        w->change("程序异常");
        w->show();
        qDebug()<<e.what();
    }

    while(!in.eof()){
        Admin *a=new Admin;
        in>>a;
        admin.push_back(a);
    }
    in.close();

    normal.clear();
    ifstream in2;
    try{
       in2.open("normal.txt");
    }
    catch(exception &e){
        wrong *w =new wrong;
        w->change("程序异常");
        w->show();
        qDebug()<<e.what();
    }
    while(!in2.eof()){
        Normal *n=new Normal;
        in2>>n;
        normal.push_back(n);
    }
    in2.close();

    board.clear();
    ifstream in1;
    try{
       in1.open("board.txt");
    }
    catch(exception &e){
        wrong *w =new wrong;
        w->change("程序异常");
        w->show();
        qDebug()<<e.what();
    }
    string s;
    //in1>>s;
    qDebug()<<QString::fromStdString(s);

    for(int i=0;i<4;i++){
        Board *b=new Board;
        in1>>s;
        //in1>>s;
        //qDebug()<<QString::fromStdString(s);
        in1>>b;
        board.push_back(b);
        //in1>>s;
        qDebug()<<QString::fromStdString(s);
        qDebug()<<"888"<<b->get_name();
    }
    in1.close();
    qDebug()<<board.size();
}

int Forum::login_in(QString name, QString password,int i){
    QString name1,password1;
    if(i==1){
        for(int j=0;j<admin.size();j++){
            name1=admin[j]->get_username();
            password1=admin[j]->get_password();
            if(name==name1 && password==password1){
                return j;
            }
        }
        return -1;
    }
    else if(i==2){
        for(int j=0;j<normal.size();j++){
            name1=normal[j]->get_username();
            password1=normal[j]->get_password();
            if(name==name1 && password==password1){
                return j;
            }
        }
        return -1;
    }
}

void Forum::login_out(){//登出
    QString id;
    if(type==1){
        id=admin_1->get_id();
        int t=f.admin.size();
        qDebug()<<t;
        for(int i=0;i<t;i++){
            if(id==f.admin[i]->get_id()){
                //f.admin.erase(f.admin.begin()+t);
                f.admin[t]=admin_1;
            }
        }
    }
    else if(type==2){
        id=normal_1->get_id();
        int t=f.normal.size();
        qDebug()<<t;
        for(int i=0;i<t;i++){
            qDebug()<<i;
            qDebug()<<id;
            qDebug()<<id;
            if(id==f.normal[i]->get_id()){
                qDebug()<<i;
                //f.admin.erase(f.admin.begin()+t);
                f.normal[t]=normal_1;
            }
        }
    }

    ofstream out;

    try{
       out.open("admin.txt");//打开文件
    }
    catch(exception &e){
        wrong *w =new wrong;
        w->change("程序异常");
        w->show();
        qDebug()<<e.what();
    }
    int t1=f.admin.size();
    for(int i=0;i<t1;i++){
        out<<f.admin[i];
    }
    out.close();
    qDebug()<<"&&&";

    ofstream out2;
    //qDebug()<<"&&&";

    try{
       out2.open("normal.txt");//打开文件
    }
    catch(exception &e){
        wrong *w =new wrong;
        w->change("程序异常");
        w->show();
        qDebug()<<e.what();
    }

    int t=f.normal.size();
    //qDebug()<<"&&&"<<t;
    for(int i=0;i<t;i++){
        if(f.normal[i]->get_username()!=""){
        out2<<f.normal[i];
        }
    }
    out2.close();

    ofstream out1;

    try{
       out1.open("board.txt");
    }
    catch(exception &e){
        wrong *w =new wrong;
        w->change("程序异常");
        w->show();
        qDebug()<<e.what();
    }
    for(int i=0;i<4;i++){
        out1<<f.board[i];
        qDebug()<<f.board[i]->get_name();
    }
    out1.close();
}
