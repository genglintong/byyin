#ifndef GLOBLE_H
#define GLOBLE_H
#include "Forum.h"
#include "Users.h"
#include "Admin.h"
#include "Normal.h"

extern int type;
extern Forum f;
extern Users *user;
extern Admin *admin_1;
extern Normal * normal_1;
extern int now_board;
extern int now_admin;
extern int now_normal;
extern int now_post;

#endif // GLOBLE_H
