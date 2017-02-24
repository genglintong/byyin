#include "see.h"
#include "ui_see.h"
#include "globle.h"

see::see(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::see)
{

    ui->setupUi(this);
    if(type==1){
        ui->mima->setText(admin_1->get_password());
        ui->name->setText(admin_1->get_username());
        ui->dengji->setText("管理员");
    }
    else if(type==2){
        QString s=QString::number(normal_1->get_level());
        ui->mima->setText(normal_1->get_password());
        ui->name->setText(normal_1->get_username());
        if(normal_1->get_master()==1){
            ui->dengji->setText("版主");
        }
        else{
        ui->dengji->setText(s);
        }
    }
}

see::~see()
{
    delete ui;
}

void see::on_pushButton_clicked()
{
    close();
}

void see::on_change_name_clicked()
{
    if(type==1){
        admin_1->change_username(ui->name->text());
    }
    else if (type==2){
        normal_1->change_username(ui->name->text());
    }
}

void see::on_change_mima_clicked()
{
    if(type==1){
        admin_1->change_password(ui->mima->text());
    }
    else if (type==2){
        normal_1->change_password(ui->mima->text());
    }
}

void see::on_see_2_clicked()
{
    if(type==1){
        ui->mima->setText(admin_1->get_password());
        ui->name->setText(admin_1->get_username());
        ui->dengji->setText("管理员");
    }
    else if(type==2){
        QString s=QString::number(normal_1->get_level());
        ui->mima->setText(normal_1->get_password());
        ui->name->setText(normal_1->get_username());
        if(normal_1->get_master()==1){
            ui->dengji->setText("版主");
        }
        else{
        ui->dengji->setText(s);
        }
    }
}
