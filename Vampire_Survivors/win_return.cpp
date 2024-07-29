
#include "win_return.h"

win_return::win_return(QWidget *parent)
    : QWidget{parent}
{
    initScene();
    QLabel* l1 = new QLabel;
    l1->setParent(this);
    l1->setAlignment(Qt::AlignCenter);
    l1->move(330,330);
    l1->setText("胜利");
    l1->setStyleSheet("color: red");
    QFont font("Arial",25);
    l1->setFont(font);
    QPushButton* b1 = new QPushButton;
    b1->setParent(this);
    b1->setText("返回主页面");
    b1->move(300,400);
    b1->resize(100,40);
    connect(b1,&QPushButton::clicked,this,[=]()
            {
               myslot_1();
            });
}
win_return::~win_return()
{

}
void win_return::initScene()
{
    setFixedSize(700,500);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));
}
void win_return::paintEvent(QPaintEvent* )
{
    QPainter painter(this);
    QString path_INITI(WIN_PATH);
    painter.drawPixmap(0,0,700,500 ,path_INITI);

}
void win_return::myslot_1()
{
    emit mysignal_1();
}

