#include "wrong.h"
#include "ui_wrong.h"
#include "denglu.h"

wrong::wrong(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wrong)
{
    ui->setupUi(this);
}

wrong::~wrong()
{
    delete ui;
}

void wrong::on_pushButton_clicked()
{
    close();
    //Denglu *l=new Denglu(this);
    //l->show();
}

void wrong::change(QString s){
    ui->label->setText("");
    ui->label_2->setText(s);
}
