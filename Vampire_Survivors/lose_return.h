
#ifndef LOSE_RETURN_H
#define LOSE_RETURN_H


#include <QWidget>
#include "config.h"
#include <QPainter>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>

class lose_return : public QWidget
{
    Q_OBJECT
public:
    explicit lose_return(QWidget *parent = nullptr);
    void initScene();
    ~lose_return();

protected:
    void paintEvent(QPaintEvent *);//画家类函数
signals:
    void mysignal_1();



public slots:
    void myslot_1();

};

#endif // LOSE_RETURN_H
