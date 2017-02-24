#ifndef POST1_H
#define POST1_H

#include <QDialog>

namespace Ui {
class post1;
}

class post1 : public QDialog
{
    Q_OBJECT

public:
    explicit post1(QWidget *parent = 0);
    ~post1();

private slots:
    void on_pushButton_clicked();

    void on_pinglun_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::post1 *ui;
};

#endif // POST1_H
