#include "command/dialog_command.h"
#include "command/door_open_command.h"
#include "command/fight_command.h"
#include "command/floor_change_command.h"
#include "command/pick_key_command.h"
#include "command/move_down_command.h"
#include "command/move_up_command.h"
#include "command/move_left_command.h"
#include "command/move_right_command.h"
#include "command/pick_item_command.h"
#include "notification/notification.h"
#include "viewmodel.h"

ViewModel::ViewModel(){
    dialog_command = std::static_pointer_cast<Command, DialogCommand>(std::shared_ptr<DialogCommand>(new DialogCommand(std::shared_ptr<ViewModel>(this))));
    door_open_command = std::static_pointer_cast<Command, DoorOpenCommand>(std::shared_ptr<DoorOpenCommand>(new DoorOpenCommand(std::shared_ptr<ViewModel>(this))));
    fight_command = std::static_pointer_cast<Command, FightCommand>(std::shared_ptr<FightCommand>(new FightCommand(std::shared_ptr<ViewModel>(this))));
    floor_change_command = std::static_pointer_cast<Command, FloorChangeCommand>(std::shared_ptr<FloorChangeCommand>(new FloorChangeCommand(std::shared_ptr<ViewModel>(this))));
    pick_key_command = std::static_pointer_cast<Command, PickKeyCommand>(std::shared_ptr<PickKeyCommand>(new PickKeyCommand(std::shared_ptr<ViewModel>(this))));
    pick_item_command = std::static_pointer_cast<Command, PickItemCommand>(std::shared_ptr<PickItemCommand>(new PickItemCommand(std::shared_ptr<ViewModel>(this))));
    move_down_command = std::static_pointer_cast<Command, MoveDownCommand>(std::shared_ptr<MoveDownCommand>(new MoveDownCommand(std::shared_ptr<ViewModel>(this))));
    move_up_command = std::static_pointer_cast<Command, MoveUpCommand>(std::shared_ptr<MoveUpCommand>(new MoveUpCommand(std::shared_ptr<ViewModel>(this))));
    move_left_command = std::static_pointer_cast<Command, MoveLeftCommand>(std::shared_ptr<MoveLeftCommand>(new MoveLeftCommand(std::shared_ptr<ViewModel>(this))));
    move_right_command = std::static_pointer_cast<Command, MoveRightCommand>(std::shared_ptr<MoveRightCommand>(new MoveRightCommand(std::shared_ptr<ViewModel>(this))));
    update_display_data_notification = std::static_pointer_cast<Notification, UpdateDisplayDataNotification>
        (std::shared_ptr<UpdateDisplayDataNotification>(new UpdateDisplayDataNotification(std::shared_ptr<ViewModel>(this))));
}

std::shared_ptr<BRAVER> ViewModel::get_braver() {return mod->get_braver();}
std::shared_ptr<FLOOR*> ViewModel::get_tower() {return mod->get_tower();}

void ViewModel::set_braver(std::shared_ptr<BRAVER> x){
    Braver = x;
}

void ViewModel::set_tower(std::shared_ptr<FLOOR*> x){
    Tower = x;
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

void ViewModel::exec_dialog_command(int x){mod->change_dialog_no(x);}

void ViewModel::exec_door_open_command(){
    set_tower(mod->get_tower());
    set_braver(mod->get_braver());
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 21 && Braver->key1 > 0){
        mod->change_key1(-1);
        mod->clear_floor();
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 22 && Braver->key2 > 0){
        mod->change_key2(-1);
        mod->clear_floor();
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 23 && Braver->key3 > 0){
        mod->change_key3(-1);
        mod->clear_floor();
    }
}

void ViewModel::exec_fight_command(int hp, int exp, int gold){}

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
        mod->clear_floor();
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 32){
        mod->change_key2(1);
        mod->clear_floor();
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 33){
        mod->change_key3(1);
        mod->clear_floor();
    }
}

void ViewModel::exec_pick_item_command(){
    set_tower(mod->get_tower());
    set_braver(mod->get_braver());
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 34){
        mod->change_hp(100);
        mod->clear_floor();
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 35){
        mod->change_hp(200);
        mod->clear_floor();
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 36){
        mod->change_atk(1);
        mod->clear_floor();
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 37){
        mod->change_pdef(1);
        mod->clear_floor();
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 38){
        mod->change_atk(10);
        mod->clear_floor();
    }
    if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 39){
        mod->change_pdef(10);
        mod->clear_floor();
    }
}

void ViewModel::exec_move_down_command(){
    set_tower(mod->get_tower());
    set_braver(mod->get_braver());
    if (Braver->pos_y >= Y - 1) mod->change_pos_y(0, 0);
    else if ((*Tower)[Braver->floor][(Braver->pos_y + 1) * X + Braver->pos_x] == 1) mod->change_pos_y(0, 0);
    else if ((*Tower)[Braver->floor][(Braver->pos_y + 1) * X + Braver->pos_x] == 21 && Braver->key1 <= 0) mod->change_pos_y(0, 0);
    else if ((*Tower)[Braver->floor][(Braver->pos_y + 1) * X + Braver->pos_x] == 22 && Braver->key2 <= 0) mod->change_pos_y(0, 0);
    else if ((*Tower)[Braver->floor][(Braver->pos_y + 1) * X + Braver->pos_x] == 23 && Braver->key3 <= 0) mod->change_pos_y(0, 0);
    else{
        Braver->have_moved = 1;
        mod->change_pos_y(1, 0);
    }
}

void ViewModel::exec_move_up_command(){
    set_tower(mod->get_tower());
    set_braver(mod->get_braver());
    std::cout << Braver->pos_x << " " << Braver->pos_y << endl;
    if (Braver->pos_y <= 0) mod->change_pos_y(0, 3);
    else if ((*Tower)[Braver->floor][(Braver->pos_y - 1) * X + Braver->pos_x] == 1) mod->change_pos_y(0, 3);
    else if ((*Tower)[Braver->floor][(Braver->pos_y - 1) * X + Braver->pos_x] == 21 && Braver->key1 <= 0) mod->change_pos_y(0, 3);
    else if ((*Tower)[Braver->floor][(Braver->pos_y - 1) * X + Braver->pos_x] == 22 && Braver->key2 <= 0) mod->change_pos_y(0, 3);
    else if ((*Tower)[Braver->floor][(Braver->pos_y - 1) * X + Braver->pos_x] == 23 && Braver->key3 <= 0) mod->change_pos_y(0, 3);
    else{
        Braver->have_moved = 1;
        //std::cout << (*Tower)[Braver->floor][(Braver->pos_y - 1) * X + Braver->pos_x] << std::endl;
        mod->change_pos_y(-1, 3);
    }
}

void ViewModel::exec_move_left_command(){
    set_tower(mod->get_tower());
    set_braver(mod->get_braver());
    if (Braver->pos_x <= 0) mod->change_pos_x(0, 1);
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x - 1] == 1) mod->change_pos_x(0, 1);
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x - 1] == 21 && Braver->key1 <= 0) mod->change_pos_x(0, 1);
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x - 1] == 22 && Braver->key2 <= 0) mod->change_pos_x(0, 1);
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x - 1] == 23 && Braver->key3 <= 0) mod->change_pos_x(0, 1);
    else{
        Braver->have_moved = 1;
        mod->change_pos_x(-1, 1);
    }
}

void ViewModel::exec_move_right_command(){
    set_tower(mod->get_tower());
    set_braver(mod->get_braver());
    if (Braver->pos_x >= X - 1) mod->change_pos_x(0, 2);
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x + 1] == 1) mod->change_pos_x(0, 2);
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x + 1] == 21 && Braver->key1 <= 0) mod->change_pos_x(0, 2);
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x + 1] == 22 && Braver->key2 <= 0) mod->change_pos_x(0, 2);
    else if ((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x + 1] == 23 && Braver->key3 <= 0) mod->change_pos_x(0, 2);
    else{
        Braver->have_moved = 1;
        mod->change_pos_x(1, 2);
    }
}

std::shared_ptr<Command> ViewModel::get_dialog_command(){
    return dialog_command;
}

std::shared_ptr<Command> ViewModel::get_door_open_command(){
    return door_open_command;
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
