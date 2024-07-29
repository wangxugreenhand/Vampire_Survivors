
#ifndef CHOOSE_SURVIVOR_SCENE_H
#define CHOOSE_SURVIVOR_SCENE_H
#include "mainscene_2.h"
#include"config.h"
#include <QWidget>
#include <iostream>
#include <fstream>

class choose_survivor_scene : public QWidget
{
    Q_OBJECT
public:

    int temp;
    mainscene_2 w_3;
    mainscene_2 w_4;
    int upgrade_survivor;
    int upgrade_weapons;
    int get_coins;
    int revive;
    int m_coins;

    explicit choose_survivor_scene(QWidget *parent = nullptr);
    ~choose_survivor_scene();
    void initScene();
    void get_data(int x1,int x2,int x3, int x4);

protected:
    void paintEvent(QPaintEvent *);//画家类函数

signals:
    void mysignal_1();
    void mysignal_2();

public slots:
    void myslot_1();
    void myslot_2();


};

#endif // CHOOSE_SURVIVOR_SCENE_H
