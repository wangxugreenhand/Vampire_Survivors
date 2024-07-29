
#include "survivors.h"
#include "config.h"

survivor::survivor(int x1, int x2,int x3,QString path)
{
    point = x1;
    power = x2;
    speed = x3;
    m_survivor.load(path);
    x = GAME_WIDTH*0.5;
    y =  GAME_HEIGHT*0.5;
    way= 1;
    m_Rect.setWidth(25);
    m_Rect.setHeight(30);
    m_Rect.moveTo(x+3,y);
    level = 1;


};
void survivor::setPosition_x(int a)
{
    if(a && x < 1470)
    {
        if((x>= 120 && x<= 150 && y >240 && y <330)||(x>= 870 && x<= 900 && y >240 && y <360)||(x>= 120 && x<= 150 && y >510 && y <600)||(x>= 870 && x<= 900 && y >510 && y <600))
            x = x;
        else
            x += speed;
    }
    else if(a && x >= 1470);

    else if(x >= speed)
    {
        if((x<= 240 && x>= 210 && y >240 && y <330)||(x<= 990 && x>= 960 && y >240 && y <360)||(x>= 210 && x<= 240 && y >510 && y <600)||(x>= 960 && x<= 990 && y >510 && y <600))
            x -= 0;
        else
            x -=speed;
    }
    else
        x = 0;
    m_Rect.moveTo(x,y);

};
void survivor::setPosition_y(int a)
{
    if(a && y < 1470)
    {
        if((y>=240 && y<=270 && x>120&& x<240) || (y>=240 && y<=270 && x>870&& x<990)|| (y>=510 && y<=540 && x>120&& x<240)|| (y>=510 && y<=540 && x>870&& x<990))
            y += 0;
        else
            y += speed;
    }
    else if(a && y == (1500 - speed))
        y = 1500 - speed;
    else if(y > 0)
    {
        if((y<=330 && y>=300 && x>120&& x<240) || (y<=330 && y>=300  && x>870&& x<990)|| (y>=570 && y<=600 && x>120&& x<240)|| (y>=570 && y<=600 && x>870&& x<990))
            y -= 0;
        else
            y-=speed;
    }
    else
        y = 0;
    m_Rect.moveTo(x,y);

    };

void survivor::update(int x)
    {
    level = x;
    point += (x-1) * 10;
    speed += (x-1) *1;
}
survivor::~survivor()
{

}
int survivor::sur_position_x()
{
    return x;
    }
int survivor::sur_position_y()
{
    return y;
}
void survivor::draw(QPainter * painter,int x)
{
    painter->save();
    painter->setPen(Qt::red);
    painter->drawRect(QRect(this->x,this->y-10,30,10));
    QBrush brush(QColor(255,0,0));
    painter->setBrush(brush);
    double g = (point * 1.0) / (x *1.0);
    painter->drawRect(QRect(this->x,this->y-10,g*30,10));
    painter->setBrush(Qt::NoBrush);
}
Antonio::Antonio():survivor(100,10,3,Antonio_p)
{
    m_recorder_1 = 0;
    BULLET_INTERVAL = 2;
    BULLET_SPEED = 5;
}

void Antonio::update_weapon(int x)
{
    this->power += (x-1)*5;
}
void Antonio::shoot()
{

    m_recorder_1 = 0;
    bullet_1* p = new bullet_1(BULLET_SPEED);
    p->m_free = false;
    p->way = this->way;
    if(this->way == 1)
    {
        p->x = this->x ;
        p->y = this->y-30;
    }
    else if(this->way == 2)
    {
        p->x = this->x ;
        p->y = this->y + 30 ;
    }
    else if(this->way == 3)
    {
        p->x = this->x - 30;
        p->y = this->y;
    }
    else if(this->way == 4)
    {
        p->x = this->x+30;
        p->y = this->y ;
    }
    Arr_bullet_1.append(p);
}
Antonio::~Antonio()
{

   };

Porta::Porta():survivor(100,10,3,Porta_p)
{
    m_cutter = new cutter(x,y-30);
};

Porta::~Porta()
{

}
void Porta::update_weapon(int x)
{
    this->m_cutter->power += (x-1)*5;
}

