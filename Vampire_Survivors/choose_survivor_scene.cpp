
#include "choose_survivor_scene.h"

choose_survivor_scene::choose_survivor_scene(QWidget *parent)
    : QWidget{parent}, w_3(1),w_4(2)
{

    initScene();
    temp =0;
    upgrade_survivor = 0;
    upgrade_weapons = 0;
    get_coins = 0;
    revive = 0;
    m_coins = 0;
    QPushButton* b1 = new QPushButton;
    QPushButton* b2 = new QPushButton;
    QPushButton* b3 = new QPushButton;
    b1->setParent(this);
    b1->setText("SURVIVOR_1");
    b1->move(300,280);
    b1->resize(60,40);
    b2->setParent(this);
    b2->setText("SURVIVOR_2");
    b2->move(400,280);
    b2->resize(60,40);
    b3->setParent(this);
    b3->setText("Continue");
    b3->move(350,350);
    b3->resize(60,40);
    connect(b1,&QPushButton::clicked,this,[=]()
            {

                this->hide();
                temp = 1;
                w_3.init_(upgrade_survivor,upgrade_weapons,get_coins,revive );
                w_3.show();
                w_3.initScene(1);
                connect(&w_3,&mainscene_2::mysignal_1,this,[=]()
                        {
                            this->m_coins = w_3.coins;

                            this->myslot_1();
                        });
                connect(&w_3,&mainscene_2::mysignal_2,this,[=]()
                        {
                            this->m_coins = w_3.coins;

                            this->myslot_2();
                        });
                connect(&w_3,&mainscene_2::mysignal_3,this,[=]()
                        {
                            this->m_coins = w_3.coins;

                            this->myslot_1();
                        });

            });
    connect(b2,&QPushButton::clicked,this,[=]()
            {
                temp = 2;
                this->hide();
                w_4.init_(upgrade_survivor,upgrade_weapons,get_coins,revive );
                w_4.show();
                w_4.initScene(2);
                connect(&w_4,&mainscene_2::mysignal_1,this,[=]()
                        {
                            this->m_coins = w_4.coins;

                            this->myslot_1();
                        });
                connect(&w_4,&mainscene_2::mysignal_2,this,[=]()
                        {
                            this->m_coins = w_4.coins;

                            this->myslot_2();
                        });
                connect(&w_4,&mainscene_2::mysignal_3,this,[=]()
                        {
                            this->m_coins = w_4.coins;

                            this->myslot_1();
                        });
            });
    connect(b3,&QPushButton::clicked,this,[=]()
            {
                std::ifstream in_file;
                in_file.open("E://Qt/Vampire_Survivors/part.txt",std::ios::in);
                if(!in_file)
                    exit(-1);
                in_file >> temp;
                if(temp== 1)
                {
                    this->hide();
                    w_3.load();
                    w_3.show();
                    w_3.initScene(1);
                    connect(&w_3,&mainscene_2::mysignal_1,this,[=]()
                        {
                            this->m_coins = w_3.coins;

                            this->myslot_1();
                        });
                    connect(&w_3,&mainscene_2::mysignal_2,this,[=]()
                        {
                            this->m_coins = w_3.coins;

                            this->myslot_2();
                        });
                    connect(&w_3,&mainscene_2::mysignal_3,this,[=]()
                        {
                            this->m_coins = w_3.coins;

                            this->myslot_1();
                        });
                }
                else if(temp == 2)
                    {
                    this->hide();
                    w_4.load();
                    w_4.show();
                    w_4.initScene(1);
                    connect(&w_4,&mainscene_2::mysignal_1,this,[=]()
                            {
                                this->m_coins = w_4.coins;

                                this->myslot_1();
                            });
                    connect(&w_4,&mainscene_2::mysignal_2,this,[=]()
                            {
                                this->m_coins = w_4.coins;

                                this->myslot_2();
                            });
                    connect(&w_4,&mainscene_2::mysignal_3,this,[=]()
                            {
                                this->m_coins = w_4.coins;

                                this->myslot_1();
                            });
                }
            });




}
choose_survivor_scene::~choose_survivor_scene()
{

}

void choose_survivor_scene::myslot_1()
{
    emit mysignal_1();
}
void choose_survivor_scene::myslot_2()
{
    emit mysignal_2();
}

void choose_survivor_scene::paintEvent(QPaintEvent* )//绘制开始页面
{
    QPainter painter(this);

    QString path_INITI(GAME_INITI_2);
    painter.drawPixmap(0,0,700,400 ,path_INITI);
    QString path1(Antonio_p);
    QString path2(":/res/Porta-pixian.png");
    painter.drawPixmap(300,200,60,60,path1);
    painter.drawPixmap(400,200,60,60,path2);

}

void choose_survivor_scene::get_data(int x1 ,int x2, int x3, int x4)
{
    upgrade_survivor = x1;
    upgrade_weapons = x2;
    get_coins = x3;
    revive = x4;
}

void choose_survivor_scene::initScene()
{
    setFixedSize(700,400);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));

}
