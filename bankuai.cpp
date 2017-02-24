#include "bankuai.h"
#include "ui_bankuai.h"
#include "globle.h"
#include "board1.h"
#include "see.h"
#include "denglu.h"
#include "choose.h"
#include <QDebug>
#include "sousuo.h"

bankuai::bankuai(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bankuai)
{
    ui->setupUi(this);

}

bankuai::~bankuai()
{
    delete ui;
}

void bankuai::on_board1_clicked()
{
    close();
    now_board=1;
    if(type==1){
        choose *c=new choose(this);
        c->show();
    }
    else{
    board1 *b=new board1(this);
    b->show();
    }
}

void bankuai::on_board2_clicked()
{
    close();
    now_board=2;
    if(type==1){
        choose *c=new choose(this);
        c->show();
    }
    else{
    board1 *b=new board1(this);
    b->show();
    }
}

void bankuai::on_board3_clicked()
{
    close();
    now_board=3;
    if(type==1){
        choose *c=new choose(this);
        c->show();
    }
    else{
    board1 *b=new board1(this);
    b->show();
    }
}


void bankuai::on_board4_clicked()
{
    close();
    now_board=4;
    if(type==1){
        choose *c=new choose(this);
        c->show();
    }
    else{
    board1 *b=new board1(this);
    b->show();
    }
}

void bankuai::on_see_clicked()
{
    see *s=new see(this);
    s->show();
}

void bankuai::on_login_out_clicked()
{
    close();
    qDebug()<<"#1";
    f.login_out();
    qDebug()<<"#2";
    Denglu *l=new Denglu(this);
    l->show();
}

void bankuai::on_sousuo_clicked()
{
    close();
    sousuo *s=new sousuo(this);
    s->show();

}
