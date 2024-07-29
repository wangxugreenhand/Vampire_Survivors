
#include "revive.h"

revive::revive(QWidget *parent)
    : QWidget{parent}
{
    initScene();
    QPushButton* b1 = new QPushButton;
    b1->setParent(this);
    b1->setText("复活！");
    b1->move(300,360);
    b1->resize(100,40);
    connect(b1,&QPushButton::clicked,this,[=]()
            {
                m--;
                myslot_1();

            });
    l1 = new QLabel;
    l1->setParent(this);
    l1->setAlignment(Qt::AlignCenter);
    l1->move(430,420);
    l1->setNum(m);
    l1->setStyleSheet("color: red");
    QFont font("Arial",25);
    l1->setFont(font);
    QLabel* l2 = new QLabel;
    l2->setParent(this);
    l2->setAlignment(Qt::AlignCenter);
    l2->move(270,420);
    l2->setText("复活次数：");
    l2->setStyleSheet("color: red");

    l2->setFont(font);
}
void revive::f()
{
    l1->setNum(m);
}
void revive::initScene()
{
    setFixedSize(700,500);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));
}
void revive::paintEvent(QPaintEvent* )
{
    QPainter painter(this);
    QString path_INITI(REVIVE_PATH);
    painter.drawPixmap(0,0,700,500 ,path_INITI);

}
void revive::myslot_1()
{
    emit mysignal_1();
}
revive::~revive()
{

}
