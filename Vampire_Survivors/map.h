
#ifndef MAP_H
#define MAP_H
#include <QPixmap>



class Map
{
public:
    Map();

    QPixmap m_map;//地图图片对象

    //地图图片X\Y轴坐标
    int map_posY;
    int map_posX;
};

#endif // MAP_H
