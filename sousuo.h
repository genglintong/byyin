#ifndef SOUSUO_H
#define SOUSUO_H
#include "Post.h"
#include <QDialog>

namespace Ui {
class sousuo;
}

class sousuo : public QDialog
{
    Q_OBJECT

public:
    explicit sousuo(QWidget *parent = 0);
    ~sousuo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::sousuo *ui;
    vector <Post *> p;
    vector <int> n;
    vector <int> m;
};

#endif // SOUSUO_H
