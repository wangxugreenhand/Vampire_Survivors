
#include "upgrade.h"

Upgrade::Upgrade(QWidget *parent)
    : QWidget{parent}
{
    initScene();
    QPushButton* b1 = new QPushButton;
    QPushButton* b2 = new QPushButton;
    QPushButton* b3 = new QPushButton;
    b1->setParent(this);
    b1->setText("增加生命值30");
    b1->move(100,200);
    b1->resize(100,40);
    b2->setParent(this);
    b2->setText("提高英雄速度");
    b2->move(100,300);
    b2->resize(100,40);
    b3->setParent(this);
    b3->setText("提升武器攻击力");
    b3->move(100,400);
    b3->resize(100,40);
    connect(b1,&QPushButton::clicked,this,&Upgrade::myslot_1);



   connect(b2,&QPushButton::clicked,this,&Upgrade::myslot_2);
   connect(b3,&QPushButton::clicked,this,&Upgrade::myslot_3);
}
void Upgrade::myslot_1()
{
    emit mysignal_1();
}
void Upgrade::myslot_2()
{
    emit mysignal_2();
}
void Upgrade::myslot_3()
{
    emit mysignal_3();
}
void Upgrade::initScene()
{
    setFixedSize(300,500);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));
}
void Upgrade::paintEvent(QPaintEvent* )
{
    QPainter painter(this);
    QString path_INITI(UPGRADE_PATH);
    painter.drawPixmap(0,0,300,500 ,path_INITI);
}
