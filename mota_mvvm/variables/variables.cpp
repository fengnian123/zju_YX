#include"variables.h"
BRAVER Braver;
MONSTER Monster[MONSTER_NUM];
FLOOR Tower[TOTAL_FLOOR];
GLOBAL_VARS Vars;

BRAVER::BRAVER()
{
    status = 0;
    level = 1;
    hp = 1000;
    atk = 10;
    pdef = 10;
    pos_x = 5;
    pos_y = 10;
    floor = 3;
    exp = 0;
    gold = 0;
    key1 = 10;
    key2 = 10;
    key3 = 10;
    status = 0;
    face = 0;
    have_moved = 0;
}

GLOBAL_VARS::GLOBAL_VARS()
{
    end_no = 0;
    dialog_no = 0;
    store_no = 1;
    OperationStatus = 0;
    OpenFloor2DoorCnt = 0;
    OpenFloor8DoorCnt = 0;
    BuyTimes = 0;
    BuyKeyInFloor6 = false;
    BuyKeyInFloor7 = false;
    CutInFloor3 = false;
}
