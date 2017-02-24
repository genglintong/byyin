#ifndef DENGLU_H
#define DENGLU_H

#include <QDialog>

namespace Ui {
class Denglu;
}

class Denglu : public QDialog
{
    Q_OBJECT

public:
    explicit Denglu(QWidget *parent = 0);
    ~Denglu();

private slots:
    void on_pushButton_clicked();

    void on_zhuce_clicked();

private:
    Ui::Denglu *ui;
};

#endif // DENGLU_H
