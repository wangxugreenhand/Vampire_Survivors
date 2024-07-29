
#ifndef MAINSCENE_2_H
#define MAINSCENE_2_H

#include <QWidget>
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include "survivors.h"
#include <QPushButton>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include "enemy.h"
#include <QVector>
#include "weapon.h"
#include <cstdlib>
#include <ctime>
#include "upgrade.h"
#include <QLabel>
#include "win_return.h"
#include "lose_return.h"
#include "revive.h"
#include <iostream>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class mainscene_2; }
QT_END_NAMESPACE

class Antonio;
class Porta;
class Upgrade;
class mainscene_2 : public QMainWindow

{
    Q_OBJECT

private:
    Antonio* a;
    Porta* p;
    Upgrade w;
    Ui::mainscene_2 *ui;
    QTimer m_timer_sur;
    QTimer m_timer_Enemy_appear_1;
    QTimer m_timer_Enemy_appear_2;
    QTimer m_timer_Survivor_attack;
    QTimer m_timer_Enemy_attack;
    QTimer m_timer;
    QTimer m_timer_Enemy_attack_2;

    //按键标志位，用于判断是否有按键按下
    bool keypressflag;
    //按键种类标志，用于判断是WSAD中的哪个
    int keyflag;
    QVector<Enemy_1*> Arr_Enemy_1;
    QVector<Enemy_2*> Arr_Enemy_2;
    int enemy_attack_recorder;
    int survivor_attack_recorder;
    int exp_recorder;
    int level;
    int weapon_level;
    int m_time_recorder;
    int h;

public:

    int temp;//状态，判断选择那个英雄。
    int coins;
    int get_coins;
    int revive_;
    int hp ;
    int i;
    QLabel* l1;
    QLabel* l3;
    QLabel* l4;
    QPushButton* b1;

    win_return m_win;
    lose_return m_lose;
    revive m_revive;
    bool m_free;



    //dddbool collide(int x1, int y1, int x2, int y2);
    explicit mainscene_2(int x,QWidget *parent = nullptr);
    ~mainscene_2();
    void mysolt();
    void initScene(int x);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
    void judgekey(survivor* a);
    void enemyToScene_1();
    void enemyToScene_2();
    void playgame_1();
    void shoot();
    void playgame_2();
    void updatePosition(survivor* a);
    void updatePosition_Enemy(survivor* a);
    void sur2_attack();
    void sur1_attack();//碰撞类函数
    void Enemy_attack(survivor* a);
    void call_upgrade();
    void upgrade_1();
    void upgrade_2();
    void upgrade_3();
    void end_win();
    void end_lose(survivor* a);
    void init_(int x1 ,int x2 ,int x3, int x4);
    void load();
    void Enemy_2_attack(survivor* a);
protected:
    void paintEvent(QPaintEvent *);//画家类函数
    void pick_coins(survivor* a);

signals:
    void mysignal_1();
    void mysignal_2();
    void mysignal_3();


public slots:
    void myslot_1();
    void myslot_2();
    void myslot_3();



};

#endif // MAINSCENE_2_H
