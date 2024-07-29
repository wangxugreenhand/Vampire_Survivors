
#ifndef WEAPON_H
#define WEAPON_H
#include "config.h"
#include <QPixmap>
//两种子弹，1是慢，伤害高；2反过来


class weapons
{
public:
    weapons(int x2);


    int power;//攻击力
    int x;
    int y;
    int level;
    int way;

};
class bullet_1:public weapons
{
public:
    bullet_1(int sp);
    void updatePosition_bullet();
    int speed;
    int way;
    bool m_free;
    QPixmap m_weapons;
    QRect m_Rect;
    QPixmap e_weapons;
};
class cutter:public weapons
{
public:

    QPixmap m_cutters_up;
    QPixmap m_cutters_down;
    QPixmap m_cutters_left;
    QPixmap m_cutters_right;
    QRect m_cutters_Rect;


    cutter(int x1,int x2);
    void updatePosition_cutter(int w,int x_, int y_);

};



#endif // WEAPON_H
