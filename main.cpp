#include <QApplication>
#include "Denglu.h"
#include "Forum.h"
#include "Users.h"
#include "Normal.h"
#include "bankuai.h"
#include "board1.h"
#include <QDebug>

using namespace std;

int type;
Forum f;
Users *user;
Admin * admin_1;
Normal * normal_1;
int now_board;
int now_admin;
int now_normal;
int now_post;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    f.Init();
    Denglu w;
    w.show();
    return a.exec();
}
