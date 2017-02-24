#ifndef ADD_H
#define ADD_H

#include <QDialog>

namespace Ui {
class add;
}

class add : public QDialog
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = 0);
    ~add();
    void A();

private slots:
    void on_add_2_clicked();

private:
    Ui::add *ui;
};

#endif // ADD_H
