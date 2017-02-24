#ifndef CHOOSE_H
#define CHOOSE_H

#include <QDialog>

namespace Ui {
class choose;
}

class choose : public QDialog
{
    Q_OBJECT

public:
    explicit choose(QWidget *parent = 0);
    ~choose();

private slots:
    void on_see_clicked();

    void on_master_clicked();

    void on_pushButton_clicked();

private:
    Ui::choose *ui;
};

#endif // CHOOSE_H
