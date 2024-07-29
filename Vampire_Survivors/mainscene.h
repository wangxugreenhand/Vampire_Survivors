
#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <iostream>
#include <fstream>
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include "choose_survivor_scene.h"
#include <QPushButton>
#include "shop.h"

class MainScene : public QMainWindow

{
    Q_OBJECT
    //survivor_1 m_survivor_1;
    choose_survivor_scene* w_2;
    SHOP w;
    int upgrade_survivor;
    int upgrade_weapons;
    int get_coins;
    int revive;
    int coins;
    int num;
protected:
    void paintEvent(QPaintEvent *);//画家类函数
public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    void initScene();
    void addAntonio();
    void shop();
    //void updata_survivor(int x);






};

#endif // MAINSCENE_H
