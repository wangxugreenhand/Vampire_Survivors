
#ifndef WIN_RETURN_H
#define WIN_RETURN_H


#include <QWidget>
#include "config.h"
#include <QPainter>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>

class win_return : public QWidget
{
    Q_OBJECT
public:
    explicit win_return(QWidget *parent = nullptr);
    void initScene();
    ~win_return();

protected:
    void paintEvent(QPaintEvent *);//画家类函数
signals:
    void mysignal_1();



public slots:
    void myslot_1();


};

#endif // WIN_RETURN_H
