
#ifndef SHOP_H
#define SHOP_H


#include <QWidget>
#include "config.h"
#include <QPainter>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>
#include <QApplication>

class SHOP : public QWidget
{
    Q_OBJECT
public:
    int m_coins;

    explicit SHOP(int x,QWidget *parent = nullptr);
    void initScene();
    void f(int x);
    QLabel* l1;

protected:
    void paintEvent(QPaintEvent *);//画家类函数
signals:
    void mysignal_1();
    void mysignal_2();
    void mysignal_3();
    void mysignal_4();
    void mysignal_5();


public slots:
    void myslot_1();
    void myslot_2();
    void myslot_3();
    void myslot_4();
    void myslot_5();

};

#endif // SHOP_H
