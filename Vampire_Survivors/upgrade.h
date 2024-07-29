
#ifndef UPGRADE_H
#define UPGRADE_H


#include <QWidget>
#include <QMainWindow>
#include <QPainter>
#include <QPushButton>
#include"config.h"

class Upgrade : public QWidget
{
    Q_OBJECT
public:
    explicit Upgrade(  QWidget *parent = nullptr);

    void initScene();
protected:
    void paintEvent(QPaintEvent *);//画家类函数

signals:
    void mysignal_1();
    void mysignal_2();
    void mysignal_3();
public slots:
    void myslot_1();
    void myslot_2();
    void myslot_3();
};

#endif // UPGRADE_H
