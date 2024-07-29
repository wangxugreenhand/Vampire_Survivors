
#include "shop.h"

SHOP::SHOP(int x, QWidget *parent)
    : QWidget{parent}
{
    initScene();
    m_coins = x;
    l1 = new QLabel;
    QLabel* l2 = new QLabel;
    QLabel* l3 = new QLabel;
    QLabel* l4 = new QLabel;
    QLabel* l5 = new QLabel;
    QLabel* l6 = new QLabel;
    l1->setParent(this);
    l1->setAlignment(Qt::AlignCenter);
    l1->move(370,400);
    l1->setNum(m_coins);
    QFont font("Arial",30);
    l1->setFont(font);

    l2->setParent(this);
    l2->setAlignment(Qt::AlignCenter);
    l2->move(200,400);
    l2->setText("金币数量:");

    l2->setFont(font);
    l3->setParent(this);
    l3->setAlignment(Qt::AlignCenter);
    l3->move(80,250);
    l3->setText("消耗5个金币");
    l3->setStyleSheet("color: red");
    l4->setParent(this);
    l4->setAlignment(Qt::AlignCenter);
    l4->move(230,250);
    l4->setText("消耗5个金币");
    l4->setStyleSheet("color: red");
    l5->setParent(this);
    l5->setAlignment(Qt::AlignCenter);
    l5->move(380,250);
    l5->setText("消耗10个金币");
    l5->setStyleSheet("color: red");
    l6->setParent(this);
    l6->setAlignment(Qt::AlignCenter);
    l6->move(550,250);
    l6->setText("消耗10个金币");
    l6->setStyleSheet("color: red");
    QPushButton* b1 = new QPushButton;
    QPushButton* b2 = new QPushButton;
    QPushButton* b3 = new QPushButton;
    QPushButton* b4 = new QPushButton;
    QPushButton* b5 = new QPushButton;

    b1->setParent(this);
    b1->setText("强化英雄属性");
    b1->move(50,200);
    b1->resize(100,40);
    b2->setParent(this);
    b2->setText("强化武器属性");
    b2->move(200,200);
    b2->resize(100,40);
    b3->setParent(this);
    b3->setText("提高金币获取系数");
    b3->move(350,200);
    b3->resize(150,40);
    b4->setParent(this);
    b4->setText("增加角色复活次数");
    b4->move(530,200);
    b4->resize(150,40);
    b5->setParent(this);
    b5->setText("返回主页面");
    b5->move(280,300);
    b5->resize(100,40);

    connect(b1,&QPushButton::clicked,this,[=]()
            {
                if(m_coins>=5)
                {
                    myslot_1();
                    m_coins -= 5;
                    l1->setNum(m_coins);
                }
            });
    connect(b2,&QPushButton::clicked,this,[=]()
            {
                if(m_coins>=5)
                {
                    myslot_2();
                    m_coins -= 5;
                    l1->setNum(m_coins);
                }

            });
    connect(b3,&QPushButton::clicked,this,[=]()
            {
                if(m_coins>=10)
                {
                    myslot_3();
                    m_coins -= 10;
                    l1->setNum(m_coins);
                }
            });
    connect(b4,&QPushButton::clicked,this,[=]()
            {
                if(m_coins>=10)
                {
                    myslot_4();
                    m_coins -= 10;
                    l1->setNum(m_coins);
                }
            });
    connect(b5,&QPushButton::clicked,this,&SHOP::myslot_5);

}
void SHOP::f(int x)
{
    m_coins = x;
    l1->setNum(m_coins);
}
void SHOP::myslot_1()
{
    emit mysignal_1();
}

void SHOP::myslot_2()
{
    emit mysignal_2();
}
void SHOP::myslot_3()
{
    emit mysignal_3();
}
void SHOP::myslot_4()
{
    emit mysignal_4();
}


void SHOP::myslot_5()
{
    emit mysignal_5();
}

void SHOP::initScene()
{
    setFixedSize(700,500);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));
}
void SHOP::paintEvent(QPaintEvent* )
{
    QPainter painter(this);
    QString path_INITI(SHOP_PATH);
    painter.drawPixmap(0,0,700,700 ,path_INITI);

}
