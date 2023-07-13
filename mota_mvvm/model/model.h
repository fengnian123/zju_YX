#ifndef MODEL_H
#define MODEL_H
#include <memory>
#include <string>
#include "variables/variables.h"
#include "notification/notification.h"

using namespace std;
class Notification;

class Model{
private:
    std::shared_ptr<Notification> update_display_data_notification;
    MONSTER Monster[MONSTER_NUM];
    GLOBAL_VARS Vars;
    std::shared_ptr<BRAVER> Braver;
    std::shared_ptr<FLOOR*> Tower_ptr;
    std::shared_ptr<MONSTER*> Monster_ptr;
    FLOOR Tower[TOTAL_FLOOR];
public:
    Model() : Braver(std::make_shared<BRAVER>()), Tower_ptr(std::make_shared<FLOOR*>(Tower)), Monster_ptr(std::make_shared<MONSTER*>(Monster)) {}
    int get_status(){return Braver->status;}
    int get_level(){return Braver->level;}
    int get_hp(){return Braver->hp;}
    int get_atk(){return Braver->atk;}
    int get_pdef(){return Braver->pdef;}
    int get_pos_x(){return Braver->pos_x;}
    int get_pos_y(){return Braver->pos_y;}
    int get_floor(){return Braver->floor;}
    int get_exp(){return Braver->exp;}
    int get_gold(){return Braver->gold;}
    int get_key1(){return Braver->key1;}
    int get_key2(){return Braver->key2;}
    int get_key3(){return Braver->key3;}
    int get_face(){return Braver->face;}

    void change_status(int x){Braver->status+=x; notify();}
    void change_level(int x){Braver->level+=x; notify();}
    void change_hp(int x){Braver->hp+=x; notify();}
    void change_atk(int x){Braver->atk+=x; notify();}
    void change_pdef(int x){Braver->pdef+=x; notify();}
    void change_pos_x(int x, int face){Braver->pos_x+=x; Braver->face = face; notify();}
    void change_pos_y(int x, int face){Braver->pos_y+=x; Braver->face = face; notify();}
    void change_floor(int x){Braver->floor+=x; notify();}
    void change_exp(int x){Braver->exp+=x; notify();}
    void change_gold(int x){Braver->gold+=x; notify();}
    void change_key1(int x){
        Braver->key1+=x;
        notify();
    }
    void change_key2(int x){
        Braver->key2+=x;
        notify();
    }
    void change_key3(int x){
        Braver->key3+=x;
        notify();
    }
    void change_face(int x){Braver->face=x; notify();}
    void clear_floor(int pos) {Tower[Braver->floor][pos] = 0; notify();}

    int get_end_no(){return Vars.end_no;} //结局编号
    int get_dialog_no(){return Vars.dialog_no;} //对话编号
    int get_store_no(){return Vars.store_no;} //商店编号
    wstring get_gain_item_msg(){return Vars.gain_item_msg;} //获得物品时显示内容
    wstring get_hint_msg(){return Vars.hint_msg;} //提示内容
    int get_OperationStatus(){return Vars.OperationStatus;} //操作状态。0为正常游戏中，1为对话框状态，2为游戏结束状态
    int get_OpenFloor2DoorCnt(){return Vars.OpenFloor2DoorCnt;} //2层和8层的门需要打败一定数量的卫兵才能打开
    int get_OpenFloor8DoorCnt(){return Vars.OpenFloor8DoorCnt;}
    int get_BuyTimes(){return Vars.BuyTimes;}
    bool get_BuyKeyInFloor6(){return Vars.BuyKeyInFloor6;}
    bool get_BuyKeyInFloor7(){return Vars.BuyKeyInFloor7;}
    bool get_CutInFloor3(){return Vars.CutInFloor3;}

    void change_end_no(int x){Vars.end_no+=x;}
    void change_dialog_no(int x){Vars.dialog_no+=x;}
    void change_store_no(int x){Vars.store_no+=x;}
    void change_gain_item_msg(wstring x){Vars.gain_item_msg=x;}
    void change_hint_msg(wstring x){Vars.hint_msg=x;}
    void change_OperationStatus(int x){Vars.OperationStatus+=x;}
    void change_OpenFloor2DoorCnt(int x){Vars.OpenFloor2DoorCnt+=x;}
    void change_OpenFloor8DoorCnt(int x){Vars.OpenFloor8DoorCnt+=x;}
    void change_BuyTimes(int x){Vars.BuyTimes+=x;}
    void change_BuyKeyInFloor6(bool x){Vars.BuyKeyInFloor6=x;}
    void change_BuyKeyInFloor7(bool x){Vars.BuyKeyInFloor7=x;}
    void change_CutInFloor3(bool x){Vars.CutInFloor3=x;}

    void set_update_display_data_notification(std::shared_ptr<Notification> notification);
    void notify();

    void init_monsters();
    void init_tower();

    int calc_damage(int pos);

    std::shared_ptr<BRAVER> get_braver() {return Braver;}
    std::shared_ptr<FLOOR*> get_tower() {return Tower_ptr;}
    std::shared_ptr<MONSTER*> get_monster() {return Monster_ptr;}
};

#endif // MODEL_H
