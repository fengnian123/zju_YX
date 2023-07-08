#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include <string>

using namespace std;

#define TOTAL_FLOOR 10 //总层数
#define X 11 //每层的x长度
#define Y 11 //每层的y长度
#define MONSTER_NUM 11 //怪物的数量

#define MOVE_LEFT 0;
#define MOVE_UP 1;
#define MOVE_RIGHT 2;
#define MOVE_DOWN 3;

#define GUI_MODE 1 //是否为图形化界面状态

typedef int FLOOR[X * Y];

void init_monsters(); //初始化全局变量
void init_tower();
#endif // LOCATION_H
