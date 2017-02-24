#ifndef BANKUAI_H
#define BANKUAI_H

#include <QDialog>

namespace Ui {
class bankuai;
}

class bankuai : public QDialog
{
    Q_OBJECT

public:
    explicit bankuai(QWidget *parent = 0);
    ~bankuai();

private slots:
    void on_board1_clicked();

    void on_board2_clicked();

    void on_board3_clicked();

    void on_board4_clicked();

    void on_see_clicked();

    void on_login_out_clicked();
    
    void on_sousuo_clicked();

private:
    Ui::bankuai *ui;
};

#endif // BANKUAI_H
