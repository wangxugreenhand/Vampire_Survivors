
#ifndef ENEMY_H
#define ENEMY_H
#include "config.h"
#include <QPainter>
#include <ctime>
#include<cstdlib>
#include "weapon.h"

class Enemy
{
public:
    int point;
    int power;
    int speed;
    bool m_free;//状态
    //坐标
    int x;
    int y;

    int attack_size;
public:
    Enemy(int x1,int x2,int x3,int x4,QString path);
    void move(int s_x,int s_y);
    bool state();
    QPixmap m_enemy;
    QRect m_Rect;

};
class Enemy_1:public Enemy//近战，生命50，攻击15，速度60
{
public:
    Enemy_1();
    void attack();
    void draw(QPainter * painter);
    int drop;
    int pick;


};
class Enemy_2:public Enemy//远程，生命50，攻击30，速度30
{
public:
//    QVector<bullet_1*> Arr_bullet_2;
    int m;
    int way;

    Enemy_2();
    void attack();
    void draw(QPainter * painter);
    void m_move();


};
#endif // ENEMY_H
