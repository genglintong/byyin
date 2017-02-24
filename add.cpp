#include "add.h"
#include "ui_add.h"
#include "globle.h"
#include <QDebug>
#include "board1.h"


add::add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
    //ui->content->setStyleSheet("border-image: url(:/byyin/边框.png);");
    //qDebug()<<"s";
}

add::~add()
{
    delete ui;
}

void add::A(){
    //ui->content->setStyleSheet("border-image: url(:/byyin/边框.png);");
    qDebug()<<"s";
}

void add::on_add_2_clicked()
{
    if(type==2){
        QString title;
        QString content;
        title=ui->title->text();
        content=ui->content->toPlainText();
        normal_1->write_post(title,content,normal_1->get_id());
        qDebug()<<"sss";
        close();
        board1 *b=new board1(this);
        b->show();
    }
}
