#include "sousuo.h"
#include "ui_sousuo.h"
#include "wrong.h"
#include "globle.h"
#include <QDebug>
#include "post1.h"
#include "bankuai.h"

sousuo::sousuo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sousuo)
{
    ui->setupUi(this);
}

sousuo::~sousuo()
{
    delete ui;
}

void sousuo::on_pushButton_clicked()
{
    QString s=ui->lineEdit->text();

    string::size_type position;
    string ss=s.toStdString();

    if(ui->title->isChecked() || ui->content->isChecked() || ui->user->isChecked()){
    if(s==""){
        wrong *w=new wrong(this);
        w->change("请输入关键词");
        w->show();
    }
    else{
        if(ui->title->isChecked()){
        p.clear();
        n.clear();
        m.clear();
        ui->listWidget->clear();
        for(int i=0;i<4;i++){
            int t=f.board[i]->P.size();
            for(int j=0;j<t;j++){
                QString title=f.board[i]->P[j]->get_title();
                position=title.toStdString().find(ss);
                qDebug()<<"$$$$"<<s<<"$$$$"<<title;
                if(position != title.toStdString().npos){
                    p.push_back(f.board[i]->P[j]);
                    n.push_back(i);
                    m.push_back(j);
                }
            }
        }
    }
    else if(ui->content->isChecked()){
        p.clear();
        n.clear();
        m.clear();
        ui->listWidget->clear();
        for(int i=0;i<4;i++){
            int t=f.board[i]->P.size();
            for(int j=0;j<t;j++){
                QString title=f.board[i]->P[j]->get_content();
                position=title.toStdString().find(ss);
                qDebug()<<"$$$$"<<s<<"$$$$"<<title;
                if(position != title.toStdString().npos){
                    p.push_back(f.board[i]->P[j]);
                    n.push_back(i);
                    m.push_back(j);
                }
            }
        }
    }
    else if(ui->user->isChecked()){
        p.clear();
        n.clear();
        m.clear();
        ui->listWidget->clear();
        for(int i=0;i<4;i++){
            int t=f.board[i]->P.size();
            for(int j=0;j<t;j++){
                QString title=f.board[i]->P[j]->get_name();
                position=title.toStdString().find(ss);
                qDebug()<<"$$$$"<<s<<"$$$$"<<title;
                if(position != title.toStdString().npos){
                    p.push_back(f.board[i]->P[j]);
                    qDebug()<<i<<j;
                    n.push_back(i);
                    m.push_back(j);
                    qDebug()<<i<<j;
                }
            }
        }
    }
    int t=p.size();
    for(int i=0;i<t;i++){
        QString sss=p[i]->get_title();
        ui->listWidget->addItem(sss);
    }
    }
    }
}

void sousuo::on_pushButton_2_clicked()
{
    int i=ui->listWidget->currentRow();
    if(i>=0){
    now_post=m[i];
    now_board=n[i]+1;
    qDebug()<<now_board<<now_post;
     post1 *p=new post1(this);
     p->show();
    }
    else{
        wrong *w=new wrong(this);
        w->change("请先选择帖子");
        w->show();
    }
}

void sousuo::on_pushButton_4_clicked()
{
    close();
    bankuai *b=new bankuai(this);
    b->show();
}
