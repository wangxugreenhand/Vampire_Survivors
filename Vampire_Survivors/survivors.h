
#ifndef SURVIVORS_H
#define SURVIVORS_H
#include <QPainter>
#include "weapon.h"


class survivor
{
    //幸存者属性
public:
    int point;//生命值
    int power;//伤害
    int speed;//速度
    //幸存者坐标
    int x;
    int y;
    int level;
    int way;//1上，2下，3左，4右


public:
    survivor(int x1,int x2, int x3,QString path);
    void weapon();
    void setPosition_x(int a);
    void setPosition_y(int a);
    ~survivor();
    int sur_position_x();
    int sur_position_y();
    void update(int x);
    void draw(QPainter * painter,int x);

    QPixmap m_survivor;
    QRect m_Rect;


};
class Antonio:public survivor//远战，100生命值，攻击5，速度30
{
public:
    Antonio();
    int BULLET_INTERVAL;
    int BULLET_SPEED;
    int m_recorder_1;
    QVector<bullet_1*> Arr_bullet_1;


    void shoot();
    void update_weapon(int x);

    ~Antonio();

};
class Porta: public survivor//近战，100生命值，攻击10，速度30
{
public:
    cutter* m_cutter;
    Porta();
    void update_weapon(int x);


    ~Porta();
};


#endif // SURVIVORS_H
