
#include "lose_return.h"

lose_return::lose_return(QWidget *parent)
    : QWidget{parent}
{
    initScene();
    QLabel* l1 = new QLabel;
    l1->setParent(this);
    l1->setAlignment(Qt::AlignCenter);
    l1->move(330,330);
    l1->setText("失败");
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
lose_return::~lose_return()
{

}
void lose_return::initScene()
{
    setFixedSize(700,500);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));
}
void lose_return::paintEvent(QPaintEvent* )
{
    QPainter painter(this);
    QString path_INITI(LOSE_PATH);
    painter.drawPixmap(0,0,700,500 ,path_INITI);

}
void lose_return::myslot_1()
{
    emit mysignal_1();
}
