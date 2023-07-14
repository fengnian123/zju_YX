#include <iostream>
#include <string>
#include "model.h"
using namespace std;

void Model::set_update_display_data_notification(std::shared_ptr<Notification> notification)
{
    this->update_display_data_notification = notification;
}

void Model::notify(){
    update_display_data_notification->exec();
}

int Model::calc_damage(int pos){
    if (Tower[Braver->floor][pos] >= 51 && Tower[Braver->floor][pos] <= 50 + MONSTER_NUM){
        int monster_id = Tower[Braver->floor][pos] - 51;
        int braver_damage = Braver->atk - Monster[monster_id].pdef;
        int monster_damage = Monster[monster_id].atk - Braver->pdef;
        return ((Monster[monster_id].hp - 1) / braver_damage) * monster_damage;
    }
    return 0;
}

int Model::break_def(int pos){
    if (Tower[Braver->floor][pos] >= 51 && Tower[Braver->floor][pos] <= 50 + MONSTER_NUM){
        int monster_id = Tower[Braver->floor][pos] - 51;
        int braver_damage = Braver->atk - Monster[monster_id].pdef;
        if (braver_damage <= 0) return 0;
    }
    return 1;
}

void Model::init_monsters(){
    Monster[0].name = L"绿色史莱姆";
    Monster[0].hp = 35;
    Monster[0].atk = 18;
    Monster[0].pdef = 1;
    Monster[0].boss = false;
    Monster[0].attrib = 0;
    Monster[0].gold = 1;
    Monster[0].exp = 0;
    Monster[0].img = ":/Graphics/Characters/003-Monster01.png";
    Monster[0].img_y = 0;

    Monster[1].name = L"红色史莱姆";
    Monster[1].hp = 45;
    Monster[1].atk = 20;
    Monster[1].pdef = 2;
    Monster[1].boss = false;
    Monster[1].attrib = 0;
    Monster[1].gold = 2;
    Monster[1].exp = 0;
    Monster[1].img = ":/Graphics/Characters/003-Monster01.png";
    Monster[1].img_y = 32;

    Monster[2].name = L"骷髅士兵";
    Monster[2].hp = 55;
    Monster[2].atk = 52;
    Monster[2].pdef = 12;
    Monster[2].boss = false;
    Monster[2].attrib = 0;
    Monster[2].gold = 8;
    Monster[2].exp = 0;
    Monster[2].img = ":/Graphics/Characters/005-Monster03.png";
    Monster[2].img_y = 32;

    Monster[3].name = L"骷髅人";
    Monster[3].hp = 50;
    Monster[3].atk = 42;
    Monster[3].pdef = 6;
    Monster[3].boss = false;
    Monster[3].attrib = 0;
    Monster[3].gold = 6;
    Monster[3].exp = 0;
    Monster[3].img = ":/Graphics/Characters/005-Monster03.png";
    Monster[3].img_y = 0;

    Monster[4].name = L"小蝙蝠";
    Monster[4].hp = 35;
    Monster[4].atk = 38;
    Monster[4].pdef = 3;
    Monster[4].boss = false;
    Monster[4].attrib = 0;
    Monster[4].gold = 3;
    Monster[4].exp = 0;
    Monster[4].img = ":/Graphics/Characters/004-Monster02.png";
    Monster[4].img_y = 0;

    Monster[5].name = L"初级法师";
    Monster[5].hp = 60;
    Monster[5].atk = 32;
    Monster[5].pdef = 8;
    Monster[5].boss = false;
    Monster[5].attrib = 0;
    Monster[5].gold = 5;
    Monster[5].exp = 0;
    Monster[5].img = ":/Graphics/Characters/007-Monster05.png";
    Monster[5].img_y = 0;

    Monster[6].name = L"中级卫兵";
    Monster[6].hp = 100;
    Monster[6].atk = 180;
    Monster[6].pdef = 110;
    Monster[6].boss = false;
    Monster[6].attrib = 0;
    Monster[6].gold = 50;
    Monster[6].exp = 0;
    Monster[6].img = ":/Graphics/Characters/008-Monster06.png";
    Monster[6].img_y = 32;

    Monster[7].name = L"初级卫兵";
    Monster[7].hp = 50;
    Monster[7].atk = 48;
    Monster[7].pdef = 22;
    Monster[7].boss = false;
    Monster[7].attrib = 0;
    Monster[7].gold = 12;
    Monster[7].exp = 0;
    Monster[7].img = ":/Graphics/Characters/008-Monster06.png";
    Monster[7].img_y = 0;

    Monster[8].name = L"魔王1";
    Monster[8].hp = 100;
    Monster[8].atk = 65;
    Monster[8].pdef = 15;
    Monster[8].boss = false;
    Monster[8].attrib = 0;
    Monster[8].gold = 30;
    Monster[8].exp = 0;
    Monster[8].img = ":/Graphics/Characters/011-Monster09.png";
    Monster[8].img_y = 0;

    Monster[9].name = L"魔王2";
    Monster[9].hp = 100;
    Monster[9].atk = 65;
    Monster[9].pdef = 15;
    Monster[9].boss = false;
    Monster[9].attrib = 0;
    Monster[9].gold = 30;
    Monster[9].exp = 0;
    Monster[9].img = ":/Graphics/Characters/011-Monster09.png";
    Monster[9].img_y = 16;

    Monster[10].name = L"魔王3";
    Monster[10].hp = 100;
    Monster[10].atk = 65;
    Monster[10].pdef = 15;
    Monster[10].boss = false;
    Monster[10].attrib = 0;
    Monster[10].gold = 30;
    Monster[10].exp = 0;
    Monster[10].img = ":/Graphics/Characters/011-Monster09.png";
    Monster[10].img_y = 32;

    Monster[11].name = L"魔王4";
    Monster[11].hp = 100;
    Monster[11].atk = 65;
    Monster[11].pdef = 15;
    Monster[11].boss = false;
    Monster[11].attrib = 0;
    Monster[11].gold = 30;
    Monster[11].exp = 0;
    Monster[11].img = ":/Graphics/Characters/011-Monster09.png";
    Monster[11].img_y = 48;
}

void Model::init_tower(){
    FLOOR tmpfloor_1 = {
        10, 0, 51, 52, 51, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        34, 0, 0, 21, 0, 1, 36, 31, 0, 1, 0,
        0, 54, 0, 1, 0, 1, 37, 34, 0, 1, 0,
        1, 21, 1, 1, 0, 1, 1, 1, 21, 1, 0,
        31, 0, 0, 1, 0, 21, 55, 56, 55, 1, 0,
        0, 53, 0, 1, 0, 1, 1, 1, 1, 1, 0,
        1, 21, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 21, 1, 1, 1, 21, 1,
        34, 0, 31, 1, 31, 0, 0, 1, 0, 55, 0,
        34, 0, 31, 1, 0, 0, 0, 1, 31, 35, 31,
    };
    memcpy(Tower[0], tmpfloor_1, sizeof(int) * X * Y);

    FLOOR tmpfloor_2 = {
        11, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 1, 0, 57, 0, 57, 0, 1, 1,
        0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
        0, 1, 31, 31, 1, 0, 0, 0, 1, 0, 51,
        0, 1, 31, 0, 21, 0, 0, 0, 21, 0, 0,
        0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
        0, 1, 52, 0, 1, 0, 0, 0, 1, 0, 53,
        0, 1, 0, 0, 21, 0, 0, 0, 21, 0, 0,
        0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
        0, 1, 35, 35, 1, 0, 0, 0, 1, 0, 0,
        10, 1, 35, 0, 21, 0, 0, 0, 21, 0, 0,
    };
    memcpy(Tower[1], tmpfloor_2, sizeof(int) * X * Y);

    FLOOR tmpfloor_3 = {
        31, 37, 1, 31, 35, 31, 1, 0, 1, 0, 35,
        0, 34, 1, 35, 31, 35, 1, 0, 21, 55, 0,
        56, 0, 1, 31, 32, 31, 1, 0, 1, 1, 1,
        21, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0,
        0, 0, 55, 0, 0, 0, 51, 0, 0, 0, 0,
        21, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1,
        54, 0, 1, 1, 0, 1, 1, 0, 1, 0, 34,
        0, 31, 1, 0, 0, 0, 1, 0, 21, 56, 31,
        34, 36, 1, 0, 13, 0, 1, 0, 1, 1, 1,
        1, 1, 1, 1, 0, 1, 1, 52, 1, 0, 0,
        11, 0, 0, 0, 0, 0, 1, 0, 21, 0, 10,
    };
    memcpy(Tower[2], tmpfloor_3, sizeof(int) * X * Y);

    FLOOR tmpfloor_4 = {
        0, 32, 0, 1, 41, 42, 43, 1, 0, 56, 0,
        34, 0, 31, 1, 0, 0, 0, 1, 31, 0, 35,
        0, 0, 0, 1, 0, 0, 0, 1, 0, 53, 0,
        1, 21, 1, 1, 1, 22, 1, 1, 1, 21, 1,
        0, 55, 0, 21, 0, 52, 0, 0, 54, 0, 0,
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
        52, 0, 51, 0, 0, 0, 0, 0, 0, 0, 0,
        21, 1, 1, 21, 1, 1, 1, 21, 1, 1, 21,
        0, 1, 0, 55, 0, 1, 0, 56, 0, 1, 0,
        0, 1, 51, 0, 31, 1, 36, 0, 34, 1, 0,
        10, 1, 31, 51, 31, 1, 0, 51, 0, 1, 11,
    };
    memcpy(Tower[3], tmpfloor_4, sizeof(int) * X * Y);

    FLOOR tmpfloor_5 = {
        10, 1, 0, 52, 21, 0, 1, 0, 0, 21, 0,
        0, 1, 0, 0, 1, 31, 1, 51, 51, 1, 52,
        0, 21, 55, 0, 1, 0, 1, 31, 31, 1, 0,
        1, 1, 1, 21, 1, 55, 1, 31, 31, 1, 0,
        31, 0, 56, 0, 1, 0, 1, 1, 1, 1, 0,
        31, 0, 0, 55, 1, 0, 51, 0, 0, 0, 0,
        1, 53, 1, 1, 1, 0, 1, 1, 1, 1, 52,
        0, 0, 0, 0, 1, 51, 1, 0, 0, 0, 0,
        37, 31, 34, 0, 1, 0, 1, 21, 1, 1, 1,
        1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0,
        11, 0, 0, 0, 0, 0, 1, 0, 26, 0, 38,
    };
    memcpy(Tower[4], tmpfloor_5, sizeof(int) * X * Y);

    FLOOR tmpfloor_6 = {
        11, 1, 31, 31, 1, 0, 56, 0, 31, 51, 0,
        0, 1, 31, 31, 1, 0, 1, 1, 1, 1, 21,
        0, 1, 1, 52, 1, 0, 1, 34, 0, 54, 0,
        0, 21, 21, 0, 21, 0, 1, 55, 0, 0, 55,
        0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
        0, 0, 52, 56, 0, 0, 0, 54, 53, 0, 0,
        1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0,
        56, 0, 0, 54, 1, 0, 21, 21, 0, 21, 0,
        0, 55, 0, 37, 1, 0, 1, 1, 52, 1, 52,
        21, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0,
        0, 51, 0, 0, 54, 0, 1, 34, 34, 1, 10,
    };
    memcpy(Tower[5], tmpfloor_6, sizeof(int) * X * Y);

    FLOOR tmpfloor_7 = {
        10, 1, 36, 1, 0, 52, 0, 1, 31, 1, 51,
        0, 1, 34, 1, 0, 0, 0, 1, 31, 1, 52,
        0, 1, 55, 1, 52, 1, 53, 1, 34, 1, 51,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        21, 1, 21, 1, 22, 1, 21, 1, 54, 1, 21,
        0, 53, 0, 56, 0, 0, 0, 0, 0, 0, 0,
        21, 1, 21, 1, 21, 1, 21, 1, 53, 1, 21,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        0, 1, 0, 1, 55, 1, 52, 1, 35, 1, 0,
        51, 1, 51, 1, 31, 1, 56, 1, 31, 1, 0,
        0, 52, 0, 1, 31, 1, 35, 1, 31, 1, 11,
    };
    memcpy(Tower[6], tmpfloor_7, sizeof(int) * X * Y);

    FLOOR tmpfloor_8 = {
        11, 0, 21, 21, 0, 10, 0, 1, 31, 0, 31,
        0, 0, 1, 1, 0, 0, 51, 1, 0, 33, 0,
        21, 1, 1, 1, 1, 21, 1, 1, 35, 0, 34,
        0, 1, 31, 31, 31, 0, 0, 1, 1, 24, 1,
        34, 1, 1, 1, 1, 1, 56, 1, 58, 0, 58,
        0, 52, 51, 52, 0, 1, 0, 1, 0, 0, 0,
        1, 1, 1, 1, 21, 1, 55, 1, 1, 21, 1,
        0, 0, 0, 55, 0, 54, 0, 56, 0, 0, 0,
        21, 1, 1, 1, 1, 1, 1, 1, 1, 1, 21,
        51, 0, 1, 36, 31, 1, 32, 34, 1, 0, 54,
        0, 55, 22, 31, 37, 1, 31, 0, 21, 53, 0,
    };
    memcpy(Tower[7], tmpfloor_8, sizeof(int) * X * Y);

    FLOOR tmpfloor_9 = {
        0, 0, 54, 21, 0, 11, 0, 21, 51, 0, 34,
        0, 31, 0, 1, 0, 0, 0, 1, 0, 51, 0,
        53, 1, 1, 1, 1, 22, 1, 1, 1, 1, 0,
        0, 31, 0, 1, 31, 0, 31, 21, 21, 0, 0,
        37, 0, 55, 21, 0, 36, 0, 1, 1, 26, 1,
        1, 1, 1, 1, 1, 1, 52, 1, 0, 0, 53,
        31, 0, 21, 53, 31, 1, 0, 1, 39, 1, 0,
        53, 0, 1, 0, 0, 1, 0, 1, 1, 1, 21,
        21, 1, 1, 1, 21, 1, 0, 1, 31, 0, 56,
        0, 34, 1, 0, 54, 1, 55, 1, 0, 54, 0,
        10, 0, 22, 0, 0, 21, 0, 21, 56, 0, 34,
    };
    memcpy(Tower[8], tmpfloor_9, sizeof(int) * X * Y);

    FLOOR tmpfloor_10 = {
        0, 0, 0, 0, 0, 44, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
        54, 54, 54, 1, 1, 0, 1, 1, 54, 54, 54,
        0, 53, 0, 24, 0, 60, 0, 24, 0, 53, 0,
        1, 1, 1, 1, 0, 62, 0, 0, 1, 1, 1,
        54, 37, 54, 1, 1, 0, 1, 1, 54, 36, 54,
        0, 53, 0, 1, 1, 0, 1, 1, 0, 53, 0,
        0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0,
        21, 1, 21, 1, 1, 23, 1, 1, 21, 1, 21,
        0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0,
        11, 1, 0, 56, 0, 0, 0, 56, 0, 1, 35,
    };
    memcpy(Tower[9], tmpfloor_10, sizeof(int) * X * Y);
}

