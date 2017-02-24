#include "choose.h"
#include "ui_choose.h"
#include "bankuai.h"
#include "globle.h"
#include "denglu.h"
#include "master.h"
#include "board1.h"

choose::choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choose)
{
    ui->setupUi(this);
}

choose::~choose()
{
    delete ui;
}

void choose::on_see_clicked()
{
    close();
    board1 *b=new board1(this);
    b->show();
}

void choose::on_master_clicked()
{
    close();
    master *m=new master(this);
    m->show();
}

void choose::on_pushButton_clicked()
{
    close();
    f.login_out();
    Denglu *l=new Denglu(this);
    l->show();
}
