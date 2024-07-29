
#include "map.h"
#include "config.h"


Map::Map()
{
    map.load(MAP_PATH);//初始化地图对象
    //设置地图坐标
    map_posX = 0;
    map_posY = 0;
}

