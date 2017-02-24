#include "master.h"
#include "ui_master.h"
#include "globle.h"
#include <QDebug>
#include "choose.h"
#include "denglu.h"

master::master(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::master)
{
    ui->setupUi(this);
    //ui->listWidget->setStyleSheet("border-image: url(:/byyin/边框.png)");

    ui->listWidget->clear();
    int t=f.normal.size();
    qDebug()<<t;
    for(int i=0;i<t;i++){
        qDebug()<<f.normal[i]->get_master();
        qDebug()<<f.normal[i]->is_board();
        if(f.normal[i]->get_master()!=0){
            if(f.normal[i]->is_board()==1){
            ui->listWidget->addItem("校园生活版主："+f.normal[i]->get_username());
            }
            else if(f.normal[i]->is_board()==2){
            ui->listWidget->addItem("谈天说地版主："+f.normal[i]->get_username());
            }
            else if(f.normal[i]->is_board()==3){
            ui->listWidget->addItem("学习生活版主："+f.normal[i]->get_username());
            }
            else if(f.normal[i]->is_board()==4){
            ui->listWidget->addItem("休闲娱乐版主："+f.normal[i]->get_username());
            }
        }
        else if(f.normal[i]->get_master()==0){
            ui->listWidget->addItem("用户："+f.normal[i]->get_username());
        }
    }
}

master::~master()
{
    delete ui;
}

void master::on_queding_clicked()
{
    if(ui->renming->isChecked()){
        int m=ui->listWidget->currentRow();
        admin_1->appoint_master(m);

    }
    else if(ui->xieren->isChecked()){
        int m=ui->listWidget->currentRow();
        //qDebug()<<f.normal[m].
        admin_1->delete_master(m);
    }
    ui->listWidget->clear();
    int t=f.normal.size();
    for(int i=0;i<t;i++){

        if(f.normal[i]->get_master()!=0){
            if(f.normal[i]->is_board()==1){
            ui->listWidget->addItem("校园生活版主："+f.normal[i]->get_username());
            }
            else if(f.normal[i]->is_board()==2){
            ui->listWidget->addItem("谈天说地版主："+f.normal[i]->get_username());
            }
            else if(f.normal[i]->is_board()==3){
            ui->listWidget->addItem("学习生活版主："+f.normal[i]->get_username());
            }
            else if(f.normal[i]->is_board()==4){
            ui->listWidget->addItem("休闲娱乐版主："+f.normal[i]->get_username());
            }
        }
        else if(f.normal[i]->get_master()==0){
            ui->listWidget->addItem("用户："+f.normal[i]->get_username());
        }
    }
}

void master::on_pushButton_clicked()
{
    close();
    f.login_out();
    Denglu *l=new Denglu(this);
    l->show();
}
