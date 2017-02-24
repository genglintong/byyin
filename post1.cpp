#include "post1.h"
#include "ui_post1.h"
#include "globle.h"
#include <QDebug>

using namespace std;


post1::post1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::post1)
{
    ui->setupUi(this);

    QString s=f.board[now_board-1]->P[now_post]->get_title();
    QString n=f.board[now_board-1]->P[now_post]->get_name();
    QString c=f.board[now_board-1]->P[now_post]->get_content();
    ui->title->setText(s);
    ui->zan->setText("赞："+QString::number(f.board[now_board-1]->P[now_post]->get_num()));
    ui->ren->setText(n);
    ui->neirongtext->setText(c);

    vector <Comment *> t=f.board[now_board-1]->P[now_post]->get_comment();
    for(int i=0;i<t.size();i++){
        QString s=t[i]->get_content();
        QString ss=t[i]->get_from();
        ui->listWidget->addItem(s+"    -by"+ss);
        //ui->listWidget->addItem(s);
    }
}

post1::~post1()
{
    delete ui;
}

void post1::on_pushButton_clicked()
{
    f.board[now_board-1]->P[now_post]->Like();
    ui->zan->setText("赞："+QString::number(f.board[now_board-1]->P[now_post]->get_num()));
    //qDebug()<<"ss";
}

void post1::on_pinglun_clicked()
{
    if(type==2 || type==3){
        normal_1->write_comment(f.board[now_board-1]->P[now_post]->get_id(),ui->pl->text());
        ui->listWidget->clear();
        vector <Comment *> t=f.board[now_board-1]->P[now_post]->get_comment();
        for(int i=0;i<t.size();i++){
            QString s=t[i]->get_content();
            QString ss=t[i]->get_from();
            ui->listWidget->addItem(s+"    -by"+ss);
        }
    }

}

void post1::on_pushButton_2_clicked()
{
    close();
}
