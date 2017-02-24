#include "board1.h"
#include "ui_board1.h"
#include "globle.h"
#include <QDebug>
#include "add.h"
#include "post1.h"
#include "bankuai.h"
#include "wrong.h"

//extern QString title;
//extern QString content;

board1::board1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::board1)
{
    ui->setupUi(this);

    ui->label->setStyleSheet("font-size : 16px");
    //ui->listWidget->setStyleSheet("border-image: url(:/byyin/边框.png)");
    if(now_board==1){
    ui->label->setText("校园生活");
    }
    else if(now_board==2){
    ui->label->setText("谈天说地");
    }
    else if(now_board==3){
    ui->label->setText("学术科技");
    }
    else if(now_board==4){
    ui->label->setText("休闲娱乐");
    }

    int t=f.board[now_board-1]->P.size();
    for(int i=0;i<t;i++){
        QString s=f.board[now_board-1]->P[i]->get_title();
        if(f.board[now_board-1]->P[i]->get_top()==1){
        ui->listWidget->addItem("【置顶】 "+s);
        }
        else{
             ui->listWidget->addItem(s);
        }
    }

}

board1::~board1()
{
    delete ui;
}


void board1::on_pushButton_clicked()
{
    if(type==2){
    close();
    add *a=new add(this);
    a->A();
    a->show();
    //qDebug()<<a;
    }
}

void board1::on_Del_clicked()
{
    qDebug()<<type;
    qDebug()<<normal_1->get_master();
    qDebug()<<normal_1->is_board()<<now_board;

    if(type==2  && normal_1->get_master()==1 && normal_1->is_board()==now_board){
        qDebug()<<"aa";

    //if(ui->listWidget->currentItem()!=Q_NULLPTR)
    //{
       //QListWidgetItem * item = ui->listWidget->takeItem(ui->listWidget->currentRow());
       int i=ui->listWidget->currentRow();
       qDebug()<<i;
       if(i>=0){
       //normal_1->delete_post(i);
       //delete item;
       f.board[now_board-1]->P.erase(f.board[now_board-1]->P.begin()+i);
       }
       qDebug()<<f.board[now_board-1]->P.size();
    //}

    ui->listWidget->clear();

    int t=f.board[now_board-1]->P.size();
    for(int i=0;i<t;i++){
        QString s=f.board[now_board-1]->P[i]->get_title();
        if(f.board[now_board-1]->P[i]->get_top()==1){
        ui->listWidget->addItem("【置顶】 "+s);
        }
        else{
             ui->listWidget->addItem(s);
        }
    }
    }
    else{
        wrong *w=new wrong(this);
        w->change("非本区版主不可删帖");
        w->show();
    }
}

void board1::on_pushButton_2_clicked()
{
    int i=ui->listWidget->currentRow();
    if(i>=0){
    now_post=ui->listWidget->currentRow();
     post1 *p=new post1(this);
     p->show();}
}

void board1::on_back_clicked()
{
    close();
    bankuai *b=new bankuai(this);
    b->show();
}

void board1::on_pushButton_3_clicked()
{
    int i=ui->listWidget->currentRow();
    if(i<0){
        wrong *w=new wrong(this);
        w->change("请选择帖子");
        w->show();
    }
    else if(type==2  && normal_1->get_master()==1 && normal_1->is_board()==now_board){

        if(f.board[now_board-1]->P[i]->get_top()!=1){
        if(i>=0){
            f.board[now_board-1]->P[i]->set_top();
            f.board[now_board-1]->P.insert(f.board[now_board-1]->P.begin(),f.board[now_board-1]->P[i]);
            f.board[now_board-1]->P.erase(f.board[now_board-1]->P.begin()+i+1);

        ui->listWidget->clear();
        int t=f.board[now_board-1]->P.size();
        for(int i=0;i<t;i++){
            QString s=f.board[now_board-1]->P[i]->get_title();
            if(f.board[now_board-1]->P[i]->get_top()==1){
            ui->listWidget->addItem("【置顶】 "+s);
            }
            else{
                 ui->listWidget->addItem(s);
            }
        }
        }
        }
        else{
            if(i>=0){
                f.board[now_board-1]->P[i]->set_notop();
                f.board[now_board-1]->P.push_back(f.board[now_board-1]->P[i]);
                f.board[now_board-1]->P.erase(f.board[now_board-1]->P.begin()+i);

            qDebug()<<"BBBBBBBB";

            ui->listWidget->clear();
            int t=f.board[now_board-1]->P.size();
            for(int i=0;i<t;i++){
                QString s=f.board[now_board-1]->P[i]->get_title();
                if(f.board[now_board-1]->P[i]->get_top()==1){
                ui->listWidget->addItem("【置顶】 "+s);
                }
                else{
                     ui->listWidget->addItem(s);
                }
            }
            }
        }
    }
    else{
        wrong *w=new wrong(this);
        w->change("非本区版主不可置顶");
        w->show();
    }
}
