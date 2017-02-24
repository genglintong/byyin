#ifndef BOARD1_H
#define BOARD1_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class board1;
}

class board1 : public QDialog
{
    Q_OBJECT

public:
    explicit board1(QWidget *parent = 0);
    ~board1();

private slots:
    void on_pushButton_clicked();
    //void on_AddEvent_clicked();
    //void on_Del_clicked();
    //void on_Modify_clicked();
    //void on_lvWid_Source_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_Del_clicked();

    //void on_new_2_clicked();

    void on_pushButton_2_clicked();

    void on_back_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::board1 *ui;
};

#endif // BOARD1_H
