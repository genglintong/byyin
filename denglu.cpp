#include "denglu.h"
#include "ui_denglu.h"
#include "globle.h"
#include "wrong.h"
#include "bankuai.h"
#include "choose.h"
#include <QDebug>

Denglu::Denglu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Denglu)
{
    ui->setupUi(this);
}

Denglu::~Denglu()
{
    delete ui;
}

void Denglu::on_pushButton_clicked()
{
    QString name=ui->name->text();
    QString password=ui->mima->text();
    if(ui->admin->isChecked()){
        int i=f.login_in(name,password,1);
        if(i!=-1){
            admin_1=f.admin[i];
            close();
            bankuai *b=new bankuai(this);
            b->show();
            now_admin=i;
            type=1;
            //登陆成功
        }
        else{
            //弹出登陆失败窗口
            wrong *w=new wrong(this);
            w->show();
        }
    }
    else if(ui->normal->isChecked()){
        int i=f.login_in(name,password,2);
        if(i!=-1){
            normal_1=f.normal[i];
            close();
            bankuai *b=new bankuai(this);
            b->show();
            now_normal=i;
            type=2;
            //登陆成功
        }
        else{
            //弹出登录失败窗口
            wrong *w=new wrong(this);
            w->show();
        }
    }
}

void Denglu::on_zhuce_clicked()
{
    QString name=ui->name->text();
    QString password=ui->mima->text();
    if(ui->admin->isChecked()){
        qDebug()<<f.login_in(name,password,1);
        if(f.login_in(name,password,1)==-1){
        Admin *a=new Admin;
        a->Init();
        a->change_password(password);
        a->change_username(name);
        a->set_id(name+password);
        f.admin.push_back(a);
        }
        else{
            wrong *w=new wrong(this);
            w->change("该信息已注册");
            w->show();
        }
    }
    else if(ui->normal->isChecked()){
        if(f.login_in(name,password,2)==-1){
        Normal *b=new Normal;
        b->Init();
        b->change_password(password);
        b->change_username(name);
        b->set_id(name+password);
        f.normal.push_back(b);
        }
        else{
            wrong *w=new wrong(this);
            w->change("该信息已注册");
            w->show();
        }
    }
}
