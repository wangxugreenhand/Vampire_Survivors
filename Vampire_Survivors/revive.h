
#ifndef REVIVE_H
#define REVIVE_H


#include <QWidget>
#include "config.h"
#include <QPainter>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>


class revive : public QWidget
{
    Q_OBJECT
public:
    explicit revive(QWidget *parent = nullptr);
    void initScene();
    ~revive();

    QLabel* l1;
    int m;

    void f();


protected:
    void paintEvent(QPaintEvent *);//画家类函数
signals:
    void mysignal_1();



public slots:
    void myslot_1();


};

#endif // REVIVE_H
