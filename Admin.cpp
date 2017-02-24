#include "Admin.h"
#include "Normal.h"
#include "globle.h"

Admin::Admin()
{

}

void Admin::appoint_master(int i){
    Master *m=new Master;
    m->change_password(f.normal[i]->get_password());
    m->change_username(f.normal[i]->get_username());
    m->set_id(m->get_username()+m->get_password());
    m->change_master(1);
    m->set_board(now_board);
    m->set_level(f.normal[i]->get_level());
    f.normal.erase(f.normal.begin()+i);
    f.normal.insert(f.normal.begin()+i,m);
}

void Admin::delete_master(int i){
    Normal *n=new Normal;
    n->change_password(f.normal[i]->get_password());
    n->change_username(f.normal[i]->get_username());
    n->set_id(n->get_username()+n->get_password());
    n->change_master(0);
    f.normal.erase(f.normal.begin()+i);
    f.normal.insert(f.normal.begin()+i,n);
}

void Admin::view_yourself(){


}
