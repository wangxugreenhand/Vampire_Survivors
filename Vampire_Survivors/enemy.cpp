
#include "enemy.h"
#include <ctime>

#define random(x) (rand()%x)

Enemy::Enemy(int x1,int x2,int x3,int x4,QString path)
{
    m_enemy.load(path);
    point = x1;
    power = x2;
    speed = x3;
    attack_size = x4;
    m_free = false;

    y = random(28);
    if(y == 0)
    {
        x = random(50) *30;
        y = y*30;
    }
    else
    {
        x = 0;
        y = y*30;
    }
    if(path == "enemy_1_p")
    {   m_Rect.setWidth(30);
        m_Rect.setHeight(30);
        m_Rect.moveTo(x,y);
    }
    else
    {
        m_Rect.setWidth(90);
        m_Rect.setHeight(90);
        m_Rect.moveTo(x-30,y-30);
    }


}
bool Enemy::state()
{
    return m_free;
}
void Enemy::move(int s_x,int s_y)
{
    if(m_free)
        return ;
    int m,n;
    if(s_x >= x)
        m = s_x - x;
    else
        m = x -s_x;
    if(s_y >=y)
        n = s_y - y;
    else
        n = y -s_y;
    if(m <= n && m >= speed && s_x > x)
    {
        x += speed;

    }
    else if(m <= n && m >= speed && s_x < x)
    {
        x -= speed;
    }
    else if(m >= n && n >= speed&& s_y > y)
    {
        y += speed;
    }
    else if(m >= n&& n >= speed && s_y < y)
    {
        y -= speed;
    }
    else if(m < speed && n >= speed&& s_y > y)
        y+=speed;
    else if(m <speed && n >= speed&& s_y < y)
        y -=speed;
    else if(n <speed && m >= speed&& s_x > x)
        x +=speed;
    else if(n < speed && m >= speed && s_x < x)
        x -=speed;
    m_Rect.moveTo(x,y);
}

Enemy_1::Enemy_1():Enemy(30,30,1,0,enemy_1_p)
{
    drop = random(6);
    pick = 0;
}
Enemy_2::Enemy_2():Enemy(30,30,1,60,enemy_2_p)
{
    m = 0;
    way = 1;
}

void Enemy_1::draw(QPainter * painter)
{

    //QString E_1_path(enemy_1_p);
    //painter->drawPixmap(x,y,30,30,E_1_path);

    painter->save();
    painter->setPen(Qt::red);
    painter->drawRect(QRect(x,y,30,30));
    QBrush brush(QColor(255,0,0));
    painter->setBrush(brush);
    painter->drawRect(QRect(x,y-10,point,10));
    painter->setBrush(Qt::NoBrush);
}

void Enemy_2::m_move()
{
    if(way == 1)
    {
        x+=speed;
        if(x >= 1470)
            way = 0;
    }
    if(way == 0)
    {
        x-=speed;
        if(x<= 0)
            way =1 ;
    }
}
void Enemy_2::draw(QPainter * painter)
{

   // QString E_2_path(enemy_2_p);
    //painter->drawPixmap(x,y,30,30,E_2_path);

    painter->save();
    painter->setPen(Qt::red);

    QBrush brush(QColor(255,0,0));
    painter->setBrush(brush);
    painter->drawRect(QRect(x,y-10,point,10));
    painter->setBrush(Qt::NoBrush);
}
