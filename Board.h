#ifndef BOARD_H
#define BOARD_H
#include<vector>
#include "Post.h"

using namespace std;

class Board
{
private:
    QString name;    
public:
    vector<Post* > P;//当前板块帖子
    Board();
    void Init(QString);
    QString get_name();
};

#endif // BOARD_H
