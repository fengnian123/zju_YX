#include "fight_command.h"
#include "floor_change_command.h"
#include "pick_key_command.h"
#include "move_down_command.h"
#include "move_up_command.h"
#include "move_left_command.h"
#include "move_right_command.h"
#include "pick_item_command.h"
#include "buy_atk_command.h"
#include "buy_def_command.h"
#include "buy_hp_command.h"
#include "notification/notification.h"
#include "viewmodel.h"

ViewModel::ViewModel(){
    fight_command = std::static_pointer_cast<Command, FightCommand>(std::shared_ptr<FightCommand>(new FightCommand(std::shared_ptr<ViewModel>(this))));
    floor_change_command = std::static_pointer_cast<Command, FloorChangeCommand>(std::shared_ptr<FloorChangeCommand>(new FloorChangeCommand(std::shared_ptr<ViewModel>(this))));
    pick_key_command = std::static_pointer_cast<Command, PickKeyCommand>(std::shared_ptr<PickKeyCommand>(new PickKeyCommand(std::shared_ptr<ViewModel>(this))));
    pick_item_command = std::static_pointer_cast<Command, PickItemCommand>(std::shared_ptr<PickItemCommand>(new PickItemCommand(std::shared_ptr<ViewModel>(this))));
    move_down_command = std::static_pointer_cast<Command, MoveDownCommand>(std::shared_ptr<MoveDownCommand>(new MoveDownCommand(std::shared_ptr<ViewModel>(this))));
    move_up_command = std::static_pointer_cast<Command, MoveUpCommand>(std::shared_ptr<MoveUpCommand>(new MoveUpCommand(std::shared_ptr<ViewModel>(this))));
    move_left_command = std::static_pointer_cast<Command, MoveLeftCommand>(std::shared_ptr<MoveLeftCommand>(new MoveLeftCommand(std::shared_ptr<ViewModel>(this))));
    move_right_command = std::static_pointer_cast<Command, MoveRightCommand>(std::shared_ptr<MoveRightCommand>(new MoveRightCommand(std::shared_ptr<ViewModel>(this))));
    buy_atk_command = std::static_pointer_cast<Command, BuyAtkCommand>(std::shared_ptr<BuyAtkCommand>(new BuyAtkCommand(std::shared_ptr<ViewModel>(this))));
    buy_def_command = std::static_pointer_cast<Command, BuyDefCommand>(std::shared_ptr<BuyDefCommand>(new BuyDefCommand(std::shared_ptr<ViewModel>(this))));
    buy_hp_command = std::static_pointer_cast<Command, BuyHpCommand>(std::shared_ptr<BuyHpCommand>(new BuyHpCommand(std::shared_ptr<ViewModel>(this))));
    update_display_data_notification = std::static_pointer_cast<Notification, UpdateDisplayDataNotification>
        (std::shared_ptr<UpdateDisplayDataNotification>(new UpdateDisplayDataNotification(std::shared_ptr<ViewModel>(this))));
}

std::shared_ptr<BRAVER> ViewModel::get_braver() {return mod->get_braver();}
std::shared_ptr<FLOOR*> ViewModel::get_tower() {return mod->get_tower();}
std::shared_ptr<MONSTER*> ViewModel::get_monster() {return mod->get_monster();}

void ViewModel::set_braver(std::shared_ptr<BRAVER> x){
    Braver = x;
}

void ViewModel::set_tower(std::shared_ptr<FLOOR*> x){
    Tower = x;
}

void ViewModel::set_monster(std::shared_ptr<MONSTER*> x){
    Monster = x;
}

void ViewModel::bind(std::shared_ptr<Model> model){
    mod = model;
}

void ViewModel::notified(){
    set_braver(mod->get_braver());
    set_tower(mod->get_tower());
    update_view_notification->exec();
}

void ViewModel::set_update_view_notification(std::shared_ptr<Notification> notification){
    update_view_notification = notification;
}

std::shared_ptr<Notification> ViewModel::get_update_display_data_notification(){
    return update_display_data_notification;
}

void ViewModel::exec_fight_command(){
    set_tower(mod->get_tower());
    set_braver(mod->get_braver());
    set_monster(mod->get_monster());
    int monster_id = (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] - 51;
    mod->change_hp(-mod->calc_damage(Braver->pos_y * X + Braver->pos_x));
    mod->change_gold((*Monster)[monster_id].gold);
    mod->change_exp((*Monster)[monster_id].exp);
    mod->clear_floor(Braver->pos_y * X + Braver->pos_x);
}

void ViewModel::exec_floor_change_command(){
    set_tower(mod->get_tower());
    set_braver(mod->get_braver());
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 11 || (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 12){
        if (Braver->have_moved){
            mod->change_floor(-1);
            Braver->have_moved = 0;
        }
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 10 || (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 14){
        if (Braver->have_moved){
            mod->change_floor(1);
            Braver->have_moved = 0;
        }
    }
}

void ViewModel::exec_pick_key_command(){
    set_tower(mod->get_tower());
    set_braver(mod->get_braver());
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 31){
        mod->change_key1(1);
        mod->clear_floor(Braver->pos_y * X + Braver->pos_x);
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 32){
        mod->change_key2(1);
        mod->clear_floor(Braver->pos_y * X + Braver->pos_x);
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 33){
        mod->change_key3(1);
        mod->clear_floor(Braver->pos_y * X + Braver->pos_x);
    }
}

void ViewModel::exec_pick_item_command(){
    set_tower(mod->get_tower());
    set_braver(mod->get_braver());
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 34){
        mod->change_hp(100);
        mod->clear_floor(Braver->pos_y * X + Braver->pos_x);
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 35){
        mod->change_hp(200);
        mod->clear_floor(Braver->pos_y * X + Braver->pos_x);
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 36){
        mod->change_atk(1);
        mod->clear_floor(Braver->pos_y * X + Braver->pos_x);
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 37){
        mod->change_pdef(1);
        mod->clear_floor(Braver->pos_y * X + Braver->pos_x);
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 38){
        mod->change_atk(10);
        mod->clear_floor(Braver->pos_y * X + Braver->pos_x);
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 39){
        mod->change_pdef(10);
        mod->clear_floor(Braver->pos_y * X + Braver->pos_x);
    }
}

void ViewModel::exec_move_down_command(){
    set_tower(mod->get_tower());
    set_braver(mod->get_braver());
    int damage = mod->calc_damage((Braver->pos_y + 1) * X + Braver->pos_x);
    if (Braver->pos_y >= Y - 1) mod->change_pos_y(0, 0);
    else if ((*Tower)[Braver->floor][(Braver->pos_y + 1) * X + Braver->pos_x] == 1) mod->change_pos_y(0, 0);
    else if ((*Tower)[Braver->floor][(Braver->pos_y + 1) * X + Braver->pos_x] >= 51 && (*Tower)[Braver->floor][(Braver->pos_y + 1) * X + Braver->pos_x] <= 50 + MONSTER_NUM && (damage >= Braver->hp || !(mod->break_def((Braver->pos_y + 1) * X + Braver->pos_x)))){
        mod->change_pos_y(0, 0);
    }
    else if ((*Tower)[Braver->floor][(Braver->pos_y + 1) * X + Braver->pos_x] == 21){
        mod->change_pos_y(0, 0);
        if (Braver->key1 > 0){
            Braver->key1 --;
            mod->clear_floor((Braver->pos_y + 1) * X + Braver->pos_x);
        }
    }
    else if ((*Tower)[Braver->floor][(Braver->pos_y + 1) * X + Braver->pos_x] == 22){
        mod->change_pos_y(0, 0);
        if (Braver->key2 > 0){
            Braver->key2 --;
            mod->clear_floor((Braver->pos_y + 1) * X + Braver->pos_x);
        }
    }
    else if ((*Tower)[Braver->floor][(Braver->pos_y + 1) * X + Braver->pos_x] == 23){
        mod->change_pos_y(0, 0);
        if (Braver->key3 > 0){
            Braver->key3 --;
            mod->clear_floor((Braver->pos_y + 1) * X + Braver->pos_x);
        }
    }
    else{
        Braver->have_moved = 1;
        mod->change_pos_y(1, 0);
    }
}

void ViewModel::exec_move_up_command(){
    set_tower(mod->get_tower());
    set_braver(mod->get_braver());
    int damage = mod->calc_damage((Braver->pos_y - 1) * X + Braver->pos_x);
    //cout << (*Tower)[Braver->floor][(Braver->pos_y - 1) * X + Braver->pos_x] << endl;
    if (Braver->pos_y <= 0) mod->change_pos_y(0, 3);
    else if ((*Tower)[Braver->floor][(Braver->pos_y - 1) * X + Braver->pos_x] == 1) mod->change_pos_y(0, 3);
    else if ((*Tower)[Braver->floor][(Braver->pos_y - 1) * X + Braver->pos_x] >= 51 && (*Tower)[Braver->floor][(Braver->pos_y - 1) * X + Braver->pos_x] <= 50 + MONSTER_NUM && (damage >= Braver->hp || !(mod->break_def((Braver->pos_y - 1) * X + Braver->pos_x)))){
        mod->change_pos_y(0, 3);
    }
    else if ((*Tower)[Braver->floor][(Braver->pos_y - 1) * X + Braver->pos_x] == 21){
        mod->change_pos_y(0, 3);
        if (Braver->key1 > 0){
            Braver->key1 --;
            mod->clear_floor((Braver->pos_y - 1) * X + Braver->pos_x);
        }
    }
    else if ((*Tower)[Braver->floor][(Braver->pos_y - 1) * X + Braver->pos_x] == 22){
        mod->change_pos_y(0, 3);
        if (Braver->key2 > 0){
            Braver->key2 --;
            mod->clear_floor((Braver->pos_y - 1) * X + Braver->pos_x);
        }
    }
    else if ((*Tower)[Braver->floor][(Braver->pos_y - 1) * X + Braver->pos_x] == 23){
        mod->change_pos_y(0, 3);
        if (Braver->key3 > 0){
            Braver->key3 --;
            mod->clear_floor((Braver->pos_y - 1) * X + Braver->pos_x);
        }
    }
    else{
        Braver->have_moved = 1;
        mod->change_pos_y(-1, 3);
    }
}

void ViewModel::exec_move_left_command(){
    set_tower(mod->get_tower());
    set_braver(mod->get_braver());
    int damage = mod->calc_damage(Braver->pos_y * X + Braver->pos_x - 1);
    if (Braver->pos_x <= 0) mod->change_pos_x(0, 1);
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x - 1] == 1) mod->change_pos_x(0, 1);
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x - 1] >= 51 && (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x - 1] <= 50 + MONSTER_NUM && (damage >= Braver->hp || !(mod->break_def(Braver->pos_y * X + Braver->pos_x - 1)))){
        mod->change_pos_y(0, 1);
    }
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x - 1] == 21){
        mod->change_pos_x(0, 1);
        if (Braver->key1 > 0){
            Braver->key1 --;
            mod->clear_floor(Braver->pos_y * X + Braver->pos_x - 1);
        }
    }
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x - 1] == 22){
        mod->change_pos_x(0, 1);
        if (Braver->key2 > 0){
            Braver->key2 --;
            mod->clear_floor(Braver->pos_y * X + Braver->pos_x - 1);
        }
    }
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x - 1] == 23){
        mod->change_pos_x(0, 1);
        if (Braver->key3 > 0){
            Braver->key3 --;
            mod->clear_floor(Braver->pos_y * X + Braver->pos_x - 1);
        }
    }
    else{
        Braver->have_moved = 1;
        mod->change_pos_x(-1, 1);
    }
}

void ViewModel::exec_move_right_command(){
    set_tower(mod->get_tower());
    set_braver(mod->get_braver());
    int damage = mod->calc_damage(Braver->pos_y * X + Braver->pos_x + 1);
    if (Braver->pos_x >= X - 1) mod->change_pos_x(0, 2);
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x + 1] == 1) mod->change_pos_x(0, 2);
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x + 1] >= 51 && (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x + 1] <= 50 + MONSTER_NUM && (damage >= Braver->hp || !(mod->break_def(Braver->pos_y * X + Braver->pos_x + 1)))){
        mod->change_pos_y(0, 2);
    }
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x + 1] == 21){
        mod->change_pos_x(0, 2);
        if (Braver->key1 > 0){
            Braver->key1 --;
            mod->clear_floor(Braver->pos_y * X + Braver->pos_x + 1);
        }
    }
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x + 1] == 22){
        mod->change_pos_x(0, 2);
        if (Braver->key2 > 0){
            Braver->key2 --;
            mod->clear_floor(Braver->pos_y * X + Braver->pos_x + 1);
        }
    }
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x + 1] == 23){
        mod->change_pos_x(0, 2);
        if (Braver->key3 > 0){
            Braver->key3 --;
            mod->clear_floor(Braver->pos_y * X + Braver->pos_x + 1);
        }
    }
    else{
        Braver->have_moved = 1;
        mod->change_pos_x(1, 2);
    }
}

void ViewModel::exec_buy_atk_command(){
    set_braver(mod->get_braver());
    if (Braver->gold >= 15){
        mod->change_atk(4);
        mod->change_gold(-15);
    }
}

void ViewModel::exec_buy_def_command(){
    set_braver(mod->get_braver());
    if (Braver->gold >= 15){
        mod->change_pdef(4);
        mod->change_gold(-15);
    }
}

void ViewModel::exec_buy_hp_command(){
    set_braver(mod->get_braver());
    if (Braver->gold >= 15){
        mod->change_hp(800);
        mod->change_gold(-15);
    }
}

std::shared_ptr<Command> ViewModel::get_fight_command(){
    return fight_command;
}

std::shared_ptr<Command> ViewModel::get_floor_change_command(){
    return floor_change_command;
}

std::shared_ptr<Command> ViewModel::get_pick_key_command(){
    return pick_key_command;
}

std::shared_ptr<Command> ViewModel::get_pick_item_command(){
    return pick_item_command;
}

std::shared_ptr<Command> ViewModel::get_move_down_command(){
    return move_down_command;
}

std::shared_ptr<Command> ViewModel::get_move_up_command(){
    return move_up_command;
}

std::shared_ptr<Command> ViewModel::get_move_left_command(){
    return move_left_command;
}

std::shared_ptr<Command> ViewModel::get_move_right_command(){
    return move_right_command;
}

std::shared_ptr<Command> ViewModel::get_buy_atk_command(){
    return buy_atk_command;
}

std::shared_ptr<Command> ViewModel::get_buy_def_command(){
    return buy_def_command;
}

std::shared_ptr<Command> ViewModel::get_buy_hp_command(){
    return buy_hp_command;
}
