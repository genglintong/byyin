#include "Board.h"

Board::Board()
{

}

void Board::Init(QString s){
    this->name=s;
}

QString Board::get_name(){
    return name;
}
