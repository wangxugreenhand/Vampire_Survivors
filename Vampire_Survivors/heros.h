
#ifndef HEROS_H
#define HEROS_H
#include <QPixmap>



class heros_1
{
    int Hit_point_1;
    int speed_1;
    int attack_power_1;
public:
    heros_1();
    void shoot();//攻击
    void setPosition(int x,int y);//设置位置
public:
    QPixmap m_hero_1;//飞机资源 对象

    //飞机坐标
    int m_x;
    int m_y;

    QRect m_Rect_1;//英雄的矩形边框

};
class heros_2
{
    int Hit_point_2;
    int speed_2;
    int attack_power_2;
public:

};

#endif // HEROS_H
