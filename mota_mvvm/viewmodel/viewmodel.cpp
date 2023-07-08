#include "command/dialog_command.h"
#include "command/door_open_command.h"
#include "command/fight_command.h"
#include "command/floor_change_command.h"
#include "command/pick_key_command.h"
#include "command/move_down_command.h"
#include "command/move_up_command.h"
#include "command/move_left_command.h"
#include "command/move_right_command.h"
#include "notification/notification.h"

ViewModel::ViewModel(){
    dialog_command = std::static_pointer_cast<Command, DialogCommand>(std::shared_ptr<DialogCommand>(new DialogCommand(std::shared_ptr<ViewModel>(this))));
    door_open_command = std::static_pointer_cast<Command, DoorOpenCommand>(std::shared_ptr<DoorOpenCommand>(new DoorOpenCommand(std::shared_ptr<ViewModel>(this))));
    fight_command = std::static_pointer_cast<Command, FightCommand>(std::shared_ptr<FightCommand>(new FightCommand(std::shared_ptr<ViewModel>(this))));
    floor_change_command = std::static_pointer_cast<Command, FloorChangeCommand>(std::shared_ptr<FloorChangeCommand>(new FloorChangeCommand(std::shared_ptr<ViewModel>(this))));
    pick_key_command = std::static_pointer_cast<Command, PickKeyCommand>(std::shared_ptr<PickKeyCommand>(new PickKeyCommand(std::shared_ptr<ViewModel>(this))));
    move_down_command = std::static_pointer_cast<Command, MoveDownCommand>(std::shared_ptr<MoveDownCommand>(new MoveDownCommand(std::shared_ptr<ViewModel>(this))));
    move_up_command = std::static_pointer_cast<Command, MoveUpCommand>(std::shared_ptr<MoveUpCommand>(new MoveUpCommand(std::shared_ptr<ViewModel>(this))));
    move_left_command = std::static_pointer_cast<Command, MoveLeftCommand>(std::shared_ptr<MoveLeftCommand>(new MoveLeftCommand(std::shared_ptr<ViewModel>(this))));
    move_right_command = std::static_pointer_cast<Command, MoveRightCommand>(std::shared_ptr<MoveRightCommand>(new MoveRightCommand(std::shared_ptr<ViewModel>(this))));
    update_display_data_notification = std::static_pointer_cast<Notification, UpdateDisplayDataNotification>
        (std::shared_ptr<UpdateDisplayDataNotification>(new UpdateDisplayDataNotification(std::shared_ptr<ViewModel>(this))));
}

void ViewModel::bind(std::shared_ptr<Model> model){
    mod = model;
}

void ViewModel::notified(){
    update_view_notification->exec();
}

void ViewModel::set_update_view_notification(std::shared_ptr<Notification> notification){
    update_view_notification = notification;
}

std::shared_ptr<Notification> ViewModel::get_update_display_data_notification(){
    return update_display_data_notification;
}

void ViewModel::exec_dialog_command(int x){mod->change_dialog_no(x);}

void ViewModel::exec_door_open_command(int door_num,int x){
    if(door_num==2) mod->change_OpenFloor2DoorCnt(x);
    if(door_num==8) mod->change_OpenFloor8DoorCnt(x);
}

void ViewModel::exec_fight_command(int hp, int exp, int gold){}

void ViewModel::exec_floor_change_command(int x){mod->change_floor(x);}

void ViewModel::exec_pick_key_command(int key_num, int x){
    if(key_num==1) mod->change_key1(x);
    if(key_num==2) mod->change_key2(x);
    if(key_num==3) mod->change_key3(x);
}

void ViewModel::exec_move_down_command(){
    if (Braver.pos_y >= Y - 1) mod->change_pos_y(0, 0);
    else mod->change_pos_y(1, 0);
}

void ViewModel::exec_move_up_command(){
    if (Braver.pos_y <= 0) mod->change_pos_y(0, 3);
    else mod->change_pos_y(-1, 3);
}

void ViewModel::exec_move_left_command(){
    if (Braver.pos_x <= 0) mod->change_pos_x(0, 1);
    else mod->change_pos_x(-1, 1);
}

void ViewModel::exec_move_right_command(){
    if (Braver.pos_x >= X - 1) mod->change_pos_x(0, 2);
    else mod->change_pos_x(1, 2);
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
