#ifndef SEE_H
#define SEE_H

#include <QDialog>

namespace Ui {
class see;
}

class see : public QDialog
{
    Q_OBJECT

public:
    explicit see(QWidget *parent = 0);
    ~see();

private slots:
    void on_pushButton_clicked();

    void on_change_name_clicked();

    void on_change_mima_clicked();

    void on_see_2_clicked();

private:
    Ui::see *ui;
};

#endif // SEE_H
