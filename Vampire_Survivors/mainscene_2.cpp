
#include "mainscene_2.h"
#include "config.h"
#include <QIcon>
#include<cmath>
//#include <QDebug>
mainscene_2::mainscene_2(int x,QWidget *parent)
    : QMainWindow(parent)
{
    h = 0;
    m_free = false;
    enemy_attack_recorder = 0;
    revive_ = 0;
    coins = 0;
    get_coins = 1;
    weapon_level = 1;
    i = 0;
    m_time_recorder = 0;
    survivor_attack_recorder = 0;
    temp = x;
    exp_recorder = 0;
    level = 1;
    hp = 100;
    keypressflag = false;
    a = new Antonio;
    p = new Porta;
    l1 = new QLabel;
    l1->setParent(this);
    l1->setAlignment(Qt::AlignCenter);
    l1->move(1290,-100);
    l1->setNum(m_time_recorder);
    l1->setStyleSheet("color: red");
    QFont font("Arial",17);
    l1->setFont(font);
    QLabel* l2 = new QLabel;
    l2->setParent(this);
    l2->setAlignment(Qt::AlignCenter);
    l2->move(1240,-100);
    l2->setText("游戏时间：");
    l2->setStyleSheet("color: red");

    l2->setFont(font);
    l4 = new QLabel;
    l4->setParent(this);
    l4->setAlignment(Qt::AlignCenter);
    l4->move(1290,150);
    l4->setNum(hp);
    l4->setStyleSheet("color: red");

    l4->setFont(font);
    l3 = new QLabel;
    l3->setParent(this);
    l3->setAlignment(Qt::AlignCenter);
    l3->move(1240,150);
    l3->setNum(hp);
    l3->setStyleSheet("color: red");

    l3->setFont(font);
    QLabel* l5 = new QLabel;
    l5->setParent(this);
    l5->setAlignment(Qt::AlignCenter);
    l5->move(1265,150);
    l5->setText("/");
    l5->setStyleSheet("color: red");

    l5->setFont(font);
    QLabel* l6 = new QLabel;
    l6->setParent(this);
    l6->setAlignment(Qt::AlignCenter);
    l6->move(1200,150);
    l6->setText("HP:");
    l6->setStyleSheet("color: red");

    l6->setFont(font);
    b1 = new QPushButton;
    b1->setParent(this);
    b1->setText("Load Game");
    b1->move(1510,700);
    b1->resize(100,40);


}
mainscene_2::~mainscene_2()
{
//    if(m_free == false)
//    {
//        myslot_3();
//    }
}

void mainscene_2::init_(int x1 ,int x2 ,int x3, int x4)
{
    level = x1;
    weapon_level = x2;
    get_coins  = x3;
    revive_ = x4;
    m_revive.m =x4;
    a->update(level);
    p->update(level);
    a->update_weapon(weapon_level);
    p->update_weapon(weapon_level);
    hp = a->point;
    l4->setNum(hp);
}

void mainscene_2::load()
{
    int x_;
    int y_;
    int point_;
    int speed_;
    int power_;
    std::ifstream in_file;
    in_file.open("E:\\Qt/Vampire_Survivors/part.txt",std::ios::in);
    if(!in_file)
        exit(-1);
    in_file >> this->temp>>x_>>y_>>point_>>power_>>speed_>>hp>>exp_recorder>>get_coins >> m_revive.m;
    if(temp == 1)
    {
        a->x = x_;
        a->y = y_;
        a->point = point_;
        a->power = power_;

    }
    else if(temp == 2)
    {
        p->x = x_;
        p->y = y_;
        p->point = point_;
        p->m_cutter->power = power_;
    }
    l4->setNum(hp);
}
void mainscene_2::initScene(int x)
{

    setFixedSize(GAME_WIDTH+150,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));
    m_timer_sur.setInterval(MOVE_RATE);
    m_timer_Enemy_appear_1.setInterval(ENEMY_INTERVAL_1);
    m_timer_Enemy_appear_2.setInterval(ENEMY_INTERVAL_2);
    m_timer_Survivor_attack.setInterval(SURVIVOR_ATTACK_RATE);
    m_timer_Enemy_attack.setInterval(ATTACK_RATE);
    m_timer.setInterval(TIME);
    m_timer_Enemy_attack_2.setInterval(ATTACK_RATE_2);
    srand((unsigned int)time(NULL));
    if(x == 1)
        playgame_1();
    else if(x == 2)
        playgame_2();
    connect(b1,&QPushButton::clicked,this,[=]()
            {
                if(temp==1)
                    {
                    std::ofstream out_file;
                    out_file.open("E://Qt/Vampire_Survivors/part.txt",std::ios::out);
                    if(!out_file)
                        exit(-1);
                    out_file<<temp<<" "<<a->x<<" "<<a->y<<" "<<a->point<<" "<<a->power<<" "<<a->speed<<" "<<hp<<" "<< exp_recorder<<" "<<get_coins<<" "<<m_revive.m;
                }
                else if(temp == 2)
                    {
                    std::ofstream out_file;
                    out_file.open("E://Qt/Vampire_Survivors/part.txt",std::ios::out);
                    if(!out_file)
                        exit(-1);
                    out_file<<temp<<" "<<p->x<<" "<<p->y<<" "<<p->point<<" "<<p->m_cutter->power<<" "<<p->speed<<" "<<hp<<" "<< exp_recorder<<" "<<get_coins<<" "<<m_revive.m;
                }
            });
}
void mainscene_2::playgame_1()
{

    m_timer_sur.start();
    m_timer_Enemy_appear_1 .start();
    m_timer_Enemy_appear_2 .start();
    m_timer_Survivor_attack .start();
    m_timer_Enemy_attack .start();
    m_timer_Enemy_attack_2 .start();
    m_timer.start();
    //监听定时器
    connect(&m_timer_sur,&QTimer::timeout,this,[=](){
        //更新游戏中元素的坐标
        updatePosition(a);
        shoot();
        updatePosition_Enemy(a);
        sur1_attack();
        Enemy_attack(a);
        pick_coins(a);
        //重新绘制图片
        update();
        end_lose(a);
        call_upgrade();

    });
    connect(&m_timer_Survivor_attack,&QTimer::timeout,this,[=](){

        a->shoot();//初始1秒两颗子弹；

        update();

    });
    connect(&m_timer_Enemy_attack,&QTimer::timeout,this,[=](){
        for(int i = 0;i<Arr_Enemy_2.count();i++)
        {
            if(Arr_Enemy_2[i]->m_free == false)
            {
                if(Arr_Enemy_2[i]->m != 2)
                    Arr_Enemy_2[i]->m++;
                else
                    Arr_Enemy_2[i]->m = 0;
            }
        }
        if(h != 2)
            h++;
        else if(h == 2)
        {
            Enemy_2_attack(a);
            h= 0;
        }
        update();

    });
    connect(&m_timer_Enemy_appear_1,&QTimer::timeout,this,[=](){
        //怪物出场
        enemyToScene_1();
        update();
    });
    connect(&m_timer_Enemy_appear_2,&QTimer::timeout,this,[=](){
        //怪物出场
        enemyToScene_2();
        update();
    });
    connect(&m_timer,&QTimer::timeout,this,[=](){

        end_win();
    });
}
void mainscene_2::playgame_2()
{
    m_timer_sur.start();
    m_timer_Enemy_appear_1 .start();
    m_timer_Enemy_appear_2 .start();
   // m_timer_Survivor_attack .start();
    m_timer_Enemy_attack .start();
    m_timer.start();
    connect(&m_timer_sur,&QTimer::timeout,this,[=](){
        //更新游戏中元素的坐标
        updatePosition(p);
        p->m_cutter->updatePosition_cutter(p->way,p->sur_position_x(),p->sur_position_y());
        updatePosition_Enemy(p);
        sur2_attack();
        Enemy_attack(p);
        pick_coins(p);
        //重新绘制图片
        update();
        end_lose(p);
        call_upgrade();

    });
    connect(&m_timer_Enemy_attack,&QTimer::timeout,this,[=](){
        for(int i = 0;i<Arr_Enemy_2.count();i++)
        {
            if(Arr_Enemy_2[i]->m_free == false)
            {
                if(Arr_Enemy_2[i]->m != 2)
                    Arr_Enemy_2[i]->m++;
                else
                    Arr_Enemy_2[i]->m = 0;
            }
        }
        if(h != 2)
            h++;
        else if(h == 2)
        {
            Enemy_2_attack(a);
            h= 0;
        }
        update();

    });
    connect(&m_timer_Enemy_appear_1,&QTimer::timeout,this,[=](){
        //怪物出场
        enemyToScene_1();
        update();
    });
    connect(&m_timer_Enemy_appear_2,&QTimer::timeout,this,[=](){
        //怪物出场
        enemyToScene_2();
        update();
    });
    connect(&m_timer,&QTimer::timeout,this,[=](){

        end_win();
    });

}
void mainscene_2::paintEvent(QPaintEvent* )
{


    QPainter painter(this);
    QString path(MAP_PATH);
    QString path_(RIGHT_PATH);
    QString exp_path(EXP_PATH);
    QString coin_path(COIN_PATH);
    QString coin_drop(COIN);
    QString weapon_drop(WEAPON);
    for(int i = 0;i<50;i++)//每个矩形块为30*30,共有50*28个
    {
        for(int j = 0;j<28;j++)
            painter.drawPixmap(30*i,30*j,30,30 ,path);
    }
    painter.drawPixmap(1500,0,200,840 ,path_);
    painter.drawRect(QRect(1510,300,100,30));
    for(int i = 0; i<exp_recorder;i++)
    {
        painter.drawPixmap(1510+20*i,300,20,30 ,exp_path);
    }

//    int b =0;
//    int c = coins / 10;
//    int d = coins %10;
//    while(c > 0)
//    {

//        for(int i = 0;i< 10;i++)

//        {
//            painter.drawPixmap(1510+10*(i-1),500+30*b,10,30 ,coin_path);
//        }
//        b++;
//    }
//    for(int i = 0;i< d;i++)
//    {
//        painter.drawPixmap(1510+10*(i-1),500+30*b,10,30 ,coin_path);
//    }




    //添加障碍物
    QString path1(OBSTACLE_1);

    painter.drawPixmap(30*5,30*9,30,30,path1);
    painter.drawPixmap(30*6,30*9,30,30,path1);
    painter.drawPixmap(30*7,30*9,30,30,path1);
    painter.drawPixmap(30*5,30*10,30,30,path1);
    painter.drawPixmap(30*6,30*10,30,30,path1);
    painter.drawPixmap(30*7,30*10,30,30,path1);
    painter.drawPixmap(30*30,30*9,30,30,path1);
    painter.drawPixmap(30*31,30*9,30,30,path1);
    painter.drawPixmap(30*32,30*9,30,30,path1);
    painter.drawPixmap(30*30,30*10,30,30,path1);
    painter.drawPixmap(30*31,30*10,30,30,path1);
    painter.drawPixmap(30*32,30*10,30,30,path1);
    painter.drawPixmap(30*5,30*18,30,30,path1);
    painter.drawPixmap(30*6,30*18,30,30,path1);
    painter.drawPixmap(30*7,30*18,30,30,path1);
    painter.drawPixmap(30*5,30*19,30,30,path1);
    painter.drawPixmap(30*6,30*19,30,30,path1);
    painter.drawPixmap(30*7,30*19,30,30,path1);
    painter.drawPixmap(30*30,30*18,30,30,path1);
    painter.drawPixmap(30*31,30*18,30,30,path1);
    painter.drawPixmap(30*32,30*18,30,30,path1);
    painter.drawPixmap(30*30,30*19,30,30,path1);
    painter.drawPixmap(30*31,30*19,30,30,path1);
    painter.drawPixmap(30*32,30*19,30,30,path1);

    Q_UNUSED(this);

    QPainter painter_(this);
    for(int i = 0;i<Arr_Enemy_1.count();i++)
    {
        if(Arr_Enemy_1[i]->m_free == false)
        {
            painter.drawPixmap(Arr_Enemy_1[i]->x,Arr_Enemy_1[i]->y,Arr_Enemy_1[i]->m_enemy);
            Arr_Enemy_1[i]->draw(&painter_);
        }
        else
        {
            if(Arr_Enemy_1[i]->drop == 1&&Arr_Enemy_1[i]->pick == 0)
            {
                painter.drawPixmap(Arr_Enemy_1[i]->x,Arr_Enemy_1[i]->y,30,30 ,coin_drop);

            }
            else if(Arr_Enemy_1[i]->drop == 2&&Arr_Enemy_1[i]->pick == 0)
            {
                painter.drawPixmap(Arr_Enemy_1[i]->x,Arr_Enemy_1[i]->y,30,30 ,weapon_drop);
            }
        }

    }
    for(int i = 0;i<Arr_Enemy_2.count();i++)
    {
        if(Arr_Enemy_2[i]->m_free == false)
        {
            painter.drawPixmap(Arr_Enemy_2[i]->x,Arr_Enemy_2[i]->y,Arr_Enemy_2[i]->m_enemy);
            Arr_Enemy_2[i]->draw(&painter_);
            if(Arr_Enemy_2[i]->m == 2)
            {
                painter.drawRect(QRect(0,Arr_Enemy_2[i]->y,1500,30));
                painter.drawRect(QRect(Arr_Enemy_2[i]->x,0,30,840));

            }
            if(Arr_Enemy_2[i]->m == 1)
            {
                painter.save();
                QBrush brush(QColor(0,255,0));
                painter.setBrush(brush);
                painter.drawRect(QRect(0,Arr_Enemy_2[i]->y+15,1500,5));
                painter.drawRect(QRect(Arr_Enemy_2[i]->x+15,0,5,840));
                painter.setBrush(Qt::NoBrush);
            }
        }


    }

    if(temp == 1)
    {
        QString path_bullet(BULLET_1_PATH);
        l3->setNum(a->point);
        painter.drawPixmap(a->sur_position_x(),a->sur_position_y(),a->m_survivor);
        a->draw(&painter,hp);

        for(int i = 0;i<a->Arr_bullet_1.count();i++)
        {
            if(a->Arr_bullet_1[i]->m_free == false)
            {
                painter.drawPixmap(a->Arr_bullet_1[i]->x,a->Arr_bullet_1[i]->y,30,30,path_bullet);
            }
        }


    }
    else if(temp == 2)
    {
        l3->setNum(p->point);


        painter.drawPixmap(p->sur_position_x(),p->sur_position_y(),p->m_survivor);
        p->draw(&painter,hp);

        if(p->way == 1)
            painter.drawPixmap(p->m_cutter->x,p->m_cutter->y,p->m_cutter->m_cutters_up);
        else if(p->way == 2)
            painter.drawPixmap(p->m_cutter->x,p->m_cutter->y,p->m_cutter->m_cutters_down);
        else if(p->way == 3)
            painter.drawPixmap(p->m_cutter->x,p->m_cutter->y,p->m_cutter->m_cutters_left);
        else if(p->way == 4)
            painter.drawPixmap(p->m_cutter->x,p->m_cutter->y,p->m_cutter->m_cutters_right);

    }
}
    //绘制开始页面
void mainscene_2::end_win()
{
    m_time_recorder++;
    l1->setNum(m_time_recorder);
    i++;
    if(i == 2)
    {
        coins += (1*get_coins);
        i = 0;
    }
    if(m_time_recorder == WIN_TIME)
    {
        m_timer_sur.stop();
        m_timer_Enemy_appear_1.stop();
        m_timer_Enemy_appear_2.stop();
        m_timer_Survivor_attack.stop();
        m_timer_Enemy_attack.stop();
        m_timer_Enemy_attack_2.stop();
        m_timer.stop();
        m_win.show();
        connect(&m_win,&win_return::mysignal_1,this,[=]()
                {
                    m_free = true;
                    this->myslot_1();

                });
    }
}
void mainscene_2::myslot_1()
{
    emit this->mysignal_1();
}
void mainscene_2::myslot_2()
{
    emit this->mysignal_2();
}
void mainscene_2::myslot_3()
{
    emit this->mysignal_3();
}
void mainscene_2::end_lose(survivor* a)
{
    if(a->point <= 0)
    {

        if(revive_>0)
        {
            m_timer_sur.stop();
            m_timer_Enemy_appear_1.stop();
            m_timer_Enemy_appear_2.stop();
            m_timer_Survivor_attack.stop();
            m_timer_Enemy_attack.stop();
            m_timer_Enemy_attack_2.stop();
            m_timer.stop();
            m_revive.f();
            m_revive.show();
            connect(&m_revive,&revive::mysignal_1,this,[=]()
                    {
                        m_free = true;
                        m_revive.hide();
                        revive_--;
                        a->point = hp;
                        m_timer_sur.start();
                        m_timer_Enemy_appear_1 .start();
                        m_timer_Enemy_appear_2 .start();
                        m_timer_Survivor_attack .start();
                        m_timer_Enemy_attack .start();
                        m_timer_Enemy_attack_2 .start();
                        m_timer.start();
                    });

        }
        else
        {
            m_timer_sur.stop();
            m_timer_Enemy_appear_1.stop();
            m_timer_Enemy_appear_2.stop();
            m_timer_Survivor_attack.stop();
            m_timer_Enemy_attack.stop();
            m_timer_Enemy_attack_2.stop();
            m_timer.stop();
            m_lose.show();
            connect(&m_lose,&lose_return::mysignal_1,this,[=]()
                    {

                        this->myslot_2();

                    });

        }
    }
}

void mainscene_2:: call_upgrade()
{
    if(exp_recorder == 5)
    {
        m_timer_sur.stop();
        m_timer_Enemy_appear_1.stop();
        m_timer_Enemy_appear_2.stop();
        m_timer_Survivor_attack.stop();
        m_timer_Enemy_attack.stop();
        m_timer_Enemy_attack_2.stop();
        m_timer.stop();
        exp_recorder = 0;
        w.show();
        connect(&w,&Upgrade::mysignal_1,this,&mainscene_2::upgrade_1);
        connect(&w,&Upgrade::mysignal_2,this,&mainscene_2::upgrade_2);
        connect(&w,&Upgrade::mysignal_3,this,&mainscene_2::upgrade_3);
    }
    else
        return;
}
void mainscene_2::upgrade_1()
{
    if(temp == 1)
    {

        hp+=30;
        a->point = hp;
        l3->setNum(a->point);
        l4->setNum(hp);
    }
    else if( temp == 2)
    {

        hp+=30;
        p->point = hp;
        l3->setNum(p->point);
        l4->setNum(hp);
    }
    w.hide();
    m_timer_sur.start();
    m_timer_Enemy_appear_1 .start();
    m_timer_Enemy_appear_2 .start();
    m_timer_Survivor_attack .start();
    m_timer_Enemy_attack .start();
    m_timer_Enemy_attack_2 .start();
    m_timer.start();

}
void mainscene_2::upgrade_2()
{
    if(temp == 1)
        a->speed++;
    else if( temp == 2)
        p->speed++;
    w.hide();
    m_timer_sur.start();
    m_timer_Enemy_appear_1 .start();
    m_timer_Enemy_appear_2 .start();
    m_timer_Survivor_attack .start();
    m_timer_Enemy_attack .start();
    m_timer_Enemy_attack_2 .start();
    m_timer.start();
}
void mainscene_2::upgrade_3()
{
    if(temp == 1)
        a->power += 5;
    else if( temp == 2)
        p->m_cutter->power += 5;
    w.hide();
    m_timer_sur.start();
    m_timer_Enemy_appear_1 .start();
    m_timer_Enemy_appear_2 .start();
    m_timer_Survivor_attack .start();
    m_timer_Enemy_attack .start();
    m_timer_Enemy_attack_2 .start();
    m_timer.start();
}
void mainscene_2::updatePosition(survivor* a)
{
    if(keypressflag)
    {
        judgekey(a);
    }
}
void mainscene_2::shoot()
{

    for(int i = 0;i<a->Arr_bullet_1.count();i++)
    {
        a->Arr_bullet_1[i]->updatePosition_bullet();
    }

}

void mainscene_2::updatePosition_Enemy(survivor* a)
{
    for(int i = 0;i<Arr_Enemy_1.count();i++)
    {
        if(Arr_Enemy_1[i]->m_free == false)
            Arr_Enemy_1[i]->move(a->sur_position_x(),a->sur_position_y());
    }
    for(int i = 0;i<Arr_Enemy_2.count();i++)
    {
        if(Arr_Enemy_2[i]->m_free == false)
            Arr_Enemy_2[i]->m_move();
    }
}

void mainscene_2::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<event->key();
    switch(event->key())
    {
    case Qt::Key_W:
        keypressflag = true;
        keyflag = 1;
        a->way = 1;
        p->way = 1;
        return ;
    case Qt::Key_S:
        keypressflag = true;
        keyflag = 2;
        a->way = 2;
        p->way = 2;
        return ;
    case Qt::Key_A:
        keypressflag = true;
        keyflag =3;
        a->way = 3;
        p->way = 3;
        return ;
    case Qt::Key_D:
        keypressflag = true;
        keyflag = 4;
        a->way = 4;
        p->way = 4;
        return ;
    }
}
void mainscene_2::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_W:
        keypressflag = false;
        return;
    case Qt::Key_S:
        keypressflag = false;
        return;

    case Qt::Key_A:
        keypressflag = false;
        return;

    case Qt::Key_D:
        keypressflag = false;
        return;
    }

}
void mainscene_2::judgekey(survivor* a)
{
    switch(keyflag)
    {
    case 1:
        a->setPosition_y(0);
        return;
    case 2:
        a->setPosition_y(1);
        return;
    case 3:
        a->setPosition_x(0);
        return;
    case 4:
        a->setPosition_x(1);
        return;
    }
}
void mainscene_2::enemyToScene_1()
{

    Enemy_1* p = new Enemy_1;
    Arr_Enemy_1.append(p);

}
void mainscene_2::enemyToScene_2()
{
    Enemy_2* q = new Enemy_2;
    Arr_Enemy_2.append(q);
}

void mainscene_2::sur1_attack()
{
    for(int i = 0;i<Arr_Enemy_1.count();i++)
    {
        if(Arr_Enemy_1[i]->m_free == true)
            continue;
        for(int j = 0;j<a->Arr_bullet_1.count();j++)
        {
            if(a->Arr_bullet_1[j]->m_free == true)
                continue;

            int x_ = Arr_Enemy_1[i]->x + 15;
            int y_ =Arr_Enemy_1[i]->y + 15;
            if(a->Arr_bullet_1[j]->x > x_ - 45 && a->Arr_bullet_1[j]->x < x_ + 15 && a->Arr_bullet_1[j]->y > y_ -45  && a->Arr_bullet_1[j]->y < y_ + 15 )
            {
                a->Arr_bullet_1[j]->m_free = true;

                Arr_Enemy_1[i]->point -= a->power;
                if(Arr_Enemy_1[i]->point <= 0)
                {
                    Arr_Enemy_1[i]->m_free = true;
                    exp_recorder++;


                }
            }
        }
    }
    for(int i = 0;i<Arr_Enemy_2.count();i++)
    {
        if(Arr_Enemy_2[i]->m_free == true)
            continue;
        for(int j = 0;j<a->Arr_bullet_1.count();j++)
        {
            if(a->Arr_bullet_1[j]->m_free == true)
                continue;

            int x_ = Arr_Enemy_2[i]->x + 15;
            int y_ =Arr_Enemy_2[i]->y + 15;
            if(a->Arr_bullet_1[j]->x > x_ - 45 && a->Arr_bullet_1[j]->x < x_ + 15 && a->Arr_bullet_1[j]->y > y_ -45  && a->Arr_bullet_1[j]->y < y_ + 15)
            {
                a->Arr_bullet_1[j]->m_free = true;

                Arr_Enemy_2[i]->point -= a->power;
                if(Arr_Enemy_2[i]->point <= 0)
                {
                    Arr_Enemy_2[i]->m_free = true;
                    exp_recorder++;
                }
            }
        }
    }
}
void mainscene_2::Enemy_attack(survivor* a)
{
    if(enemy_attack_recorder < 25)
    {
        enemy_attack_recorder++;
        return;
    }
    enemy_attack_recorder = 0;
    for(int i = 0;i<Arr_Enemy_1.count();i++)
    {
        if(Arr_Enemy_1[i]->m_free == true)
            continue;
        else
        {

            int x_ = Arr_Enemy_1[i]->x + 15;
            int y_ =Arr_Enemy_1[i]->y + 15;
            if(a->x > x_ - 45 && a->x < x_ + 15 && a->y > y_ -45  && a->y < y_ + 15)
                a->point -= Arr_Enemy_1[i]->power;
            if(a->point <= 0)
                a->point = 0;
        }
    }
    for(int i = 0;i<Arr_Enemy_2.count();i++)
    {
        if(Arr_Enemy_2[i]->m_free == true)
            continue;
        else
        {
            int x_ = Arr_Enemy_2[i]->x + 15;
            int y_ =Arr_Enemy_2[i]->y + 15;
            if(a->x > x_ - 60 && a->x < x_ + 30 && a->y > y_ -60  && a->y < y_ + 30)
                a->point -= Arr_Enemy_2[i]->power;
            if(a->point <= 0)
                a->point = 0;
        }
    }
}
void mainscene_2::sur2_attack()
{
    if(survivor_attack_recorder < 25)
    {
        survivor_attack_recorder++;
        return;
    }
    survivor_attack_recorder= 0;
    for(int i = 0;i<Arr_Enemy_1.count();i++)
    {
        if(Arr_Enemy_1[i]->m_free == true)
            continue;

        int x_ = Arr_Enemy_1[i]->x + 15;
        int y_ =Arr_Enemy_1[i]->y + 15;
        if(p->m_cutter->x > x_ - 45 && p->m_cutter->x < x_ + 15 && p->m_cutter->y > y_ -45  && p->m_cutter->y < y_ + 15)
        {
            Arr_Enemy_1[i]->point -= p->m_cutter->power;
            if(Arr_Enemy_1[i]->point <= 0)
            {
                exp_recorder++;
                Arr_Enemy_1[i]->m_free = true;
            }
        }
    }
    for(int i = 0;i<Arr_Enemy_2.count();i++)
    {
        if(Arr_Enemy_2[i]->m_free == true)
            continue;

        int x_ = Arr_Enemy_2[i]->x + 15;
        int y_ =Arr_Enemy_2[i]->y + 15;
        if(p->m_cutter->x > x_ - 45 && p->m_cutter->x < x_ + 15 && p->m_cutter->y > y_ -45  && p->m_cutter->y < y_ + 15)
        {
            Arr_Enemy_2[i]->point -= p->m_cutter->power;
            if(Arr_Enemy_2[i]->point <= 0)
            {
                exp_recorder++;
                Arr_Enemy_2[i]->m_free = true;
            }
        }
    }
    return;
}

void mainscene_2::Enemy_2_attack(survivor* a)
{
    for(int i = 0;i<Arr_Enemy_2.count();i++)
    {
        if(Arr_Enemy_2[i]->m_free == true)
            continue;
        else
        {
            int x_ = Arr_Enemy_2[i]->x;
            int y_ = Arr_Enemy_2[i]->y;
            if((a->x <= x_ +28 && a->x >= x_ - 28) || (a->y <= y_ + 30 && a->y >= y_ - 30))
                a->point -= Arr_Enemy_2[i]->power;
            if(a->point <= 0)
                a->point = 0;
        }
    }
}
void mainscene_2::pick_coins(survivor* a)
{
    for(int i = 0;i<Arr_Enemy_1.count();i++)
    {
        if(Arr_Enemy_1[i]->m_free == true &&Arr_Enemy_1[i]->drop == 1&&Arr_Enemy_1[i]->pick == 0 )
        {
            int x_ = Arr_Enemy_1[i]->x + 15;
            int y_ =Arr_Enemy_1[i]->y + 15;
            if(a->x > x_ - 45 && a->x < x_ + 15 && a->y > y_ -45  && a->y < y_ + 15)
            {
                Arr_Enemy_1[i]->pick = 1;
                coins+=5;
            }
        }
        if(Arr_Enemy_1[i]->m_free == true &&Arr_Enemy_1[i]->drop == 2&&Arr_Enemy_1[i]->pick == 0 )
        {
            int x_ = Arr_Enemy_1[i]->x + 15;
            int y_ =Arr_Enemy_1[i]->y + 15;
            if(a->x > x_ - 45 && a->x < x_ + 15 && a->y > y_ -45  && a->y < y_ + 15)
            {
                Arr_Enemy_1[i]->pick = 1;
                if(this->temp == 1)
                    a->power+=5;
                else if(temp == 2)
                    p->m_cutter->power+=5;
            }
        }
    }
}
