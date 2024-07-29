#include "config.h"
#include "mainscene.h"
//#include "survivors.cpp"
#include <QIcon>
//#include <QPushButton>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent),w(10)
{


    w_2 = new choose_survivor_scene;
    upgrade_survivor = 1;
    upgrade_weapons = 1;
    get_coins = 1;
    revive = 0;
    coins = 0;
    num =1;
//    QSoundEffect* m_music = new QSoundEffect(this);
//    m_music->setSource(QUrl::fromLocalFile(MUSIC_PATH));
//    m_music->play();
    initScene();
    QPushButton* b1 = new QPushButton;
    b1->setParent(this);
    b1->setText("START");
    b1->move(190,300);
    b1->resize(60,40);
    QPushButton* b2 = new QPushButton;
    b2->setParent(this);
    b2->setText("SHOP");
    b2->move(300,300);
    b2->resize(60,40);
    QPushButton* b3 = new QPushButton;
    b3->setParent(this);
    b3->setText("RESTART");
    b3->move(400,300);
    b3->resize(60,40);

    std::ifstream in_file;
    in_file.open("E://Qt/Vampire_Survivors/myfile.txt",std::ios::in);
    if(!in_file)
        exit(-1);
    in_file >> upgrade_survivor>>upgrade_weapons>>get_coins>>revive>>coins;

    connect(b1,&QPushButton::clicked,this,[=]()
    {
                if(w_2 == NULL)
                    {
                    w_2 = new choose_survivor_scene;
                }
                this->hide();
                    w_2->get_data(upgrade_survivor,upgrade_weapons,get_coins,revive );
                    w_2->show();
                    connect(w_2,&choose_survivor_scene::mysignal_1,this,[=]()
                            {
                                this->coins += w_2->m_coins;
                                if(w_2->temp == 1)
                                {
                                    w_2->w_3.m_win.hide();
                                    this->show();
                                    w_2->~choose_survivor_scene();
                                    w_2 = NULL;

                                }
                                else if(w_2->temp == 2)
                                {
                                    w_2->w_4.m_win.hide();
                                    this->show();
                                    w_2->~choose_survivor_scene();
                                    w_2 = NULL;
                                }
                                w.f(coins);
                            });
                    connect(w_2,&choose_survivor_scene::mysignal_2,this,[=]()
                            {
                                this->coins += w_2->m_coins;
                                if(w_2->temp == 1)
                                {
                                    w_2->w_3.m_lose.hide();
                                    this->show();
                                    w_2->~choose_survivor_scene();
                                    w_2 = NULL;

                                }
                                else if(w_2->temp == 2)
                                {
                                    w_2->w_4.m_lose.hide();
                                    this->show();
                                    w_2->~choose_survivor_scene();
                                    w_2 = NULL;
                                }
                                w.f(coins);
                            });


            });

    //关闭窗口
    connect(b2,&QPushButton::clicked,this,[=]()
            {
                w.f(coins);
                this->hide();
                w.show();

                shop();
            });
    connect(b3,&QPushButton::clicked,this,[=]()
            {
                upgrade_survivor = 1;
                upgrade_weapons = 1;
                get_coins = 1;
                revive = 0;
                coins = 0;
                w.f(coins);

            });
//    connect(b4,&QPushButton::clicked,this,[=]()
//            {
//                if(w_2 == NULL)
//                {
//                    w_2 = new choose_survivor_scene;
//                }
//                this->hide();
//                w_2->Load();

//            });

}
void MainScene::shop()
{
    connect(&w,&SHOP::mysignal_1,this,[=]()
            {
                upgrade_survivor++;
                coins-=5;

            });
    connect(&w,&SHOP::mysignal_2,this,[=]()
            {
//                w.hide();
//                this->show();
                upgrade_weapons++;
                coins-=5;
            });
    connect(&w,&SHOP::mysignal_3,this,[=]()
            {
//                w.hide();
//                this->show();
                get_coins++;
                coins-=10;
            });
    connect(&w,&SHOP::mysignal_4,this,[=]()
            {
//                w.hide();
//                this->show();
                coins-=10;
                revive++;
            });

    connect(&w,&SHOP::mysignal_5,this,[=]()
            {
                w.hide();
                this->show();
            });
}

MainScene::~MainScene()
{
    std::ofstream out_file;
    out_file.open("E://Qt/Vampire_Survivors/myfile.txt",std::ios::out);
    if(!out_file)
        exit(-1);
    out_file<<upgrade_survivor<<' '<<upgrade_weapons<<" "<<get_coins<<" "<<revive<<" "<<coins;
}
void MainScene::paintEvent(QPaintEvent* )//绘制开始页面
{
    QPainter painter(this);

    QString path_INITI(GAME_INITI);
    painter.drawPixmap(0,0,700,400 ,path_INITI);


}
void MainScene::initScene()
{
    setFixedSize(700,400);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));

}


