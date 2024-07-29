
#include "weapon.h"



weapons::weapons(int x2)
{
    power  = x2;
    level = 1;
    way = 1;
    power = x2;

}
void bullet_1:: updatePosition_bullet()
{
    if(way == 1)
    {
        y -= speed;
        m_Rect.moveTo(x,y);
        if(y <= -m_Rect.height())
        {
            m_free = true;
        }
    }
    else if(way == 2)
    {
        y += speed;
        m_Rect.moveTo(x,y);
        if(y >= GAME_HEIGHT)
        {
            m_free = true;
        }
    }
    else if(way == 3)
    {
        x -= speed;
        m_Rect.moveTo(x,y);
        if(x <= -m_Rect.width())
        {
            m_free = true;
        }
    }
    else if(way == 4)
    {
        x += speed;
        m_Rect.moveTo(x,y);
        if(x >= GAME_WIDTH)
        {
            m_free = true;
        }
    }
    m_Rect.moveTo(x,y);

}

bullet_1::bullet_1(int sp):weapons(15)
{
    speed = sp;
    m_free = false;
    m_weapons.load(BULLET_1_PATH );
    e_weapons.load(BULLET_2_PATH);
    x = 700;
    y = 400;
    m_Rect.setWidth(30);
    m_Rect.setHeight(30);
    m_Rect.moveTo(x,y);
}
cutter::cutter(int x1, int y1):weapons(10)
{
    m_cutters_up.load(WEAPON_UP);
    m_cutters_down.load(WEAPON_DOWN);
    m_cutters_left.load(WEAPON_LEFT);
    m_cutters_right.load(WEAPON_RIGHT);
    x = x1;
    y = y1;
    m_cutters_Rect.setWidth(30);
    m_cutters_Rect.setHeight(30);
    m_cutters_Rect.moveTo(x,y);
}
void cutter::updatePosition_cutter(int w,int x_,int y_)
{
    this->way = w;
    if(w == 1)
    {
        x = x_;
        y = y_ - 30;
    }
    else if(w == 2)
    {
        y = y_+30;
        x = x_;
    }
    else if(w == 3)
    {
        x = x_ - 30;
        y = y_;
    }
    else if(w == 4)
    {
        x = x_ + 30;
        y = y_;
    }
    m_cutters_Rect.moveTo(x,y);
}


