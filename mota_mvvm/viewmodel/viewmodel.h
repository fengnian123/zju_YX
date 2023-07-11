#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include "model/model.h"
#include <memory>
#include "command/command.h"
#include "notification/notification.h"

class Model;
class Notification;
class Command;

class ViewModel
{
private:
    std::shared_ptr<Model> mod;
    std::shared_ptr<Command> dialog_command;
    std::shared_ptr<Command> door_open_command;
    std::shared_ptr<Command> fight_command;
    std::shared_ptr<Command> floor_change_command;
    std::shared_ptr<Command> pick_key_command;
    std::shared_ptr<Command> pick_item_command;
    std::shared_ptr<Command> move_down_command;
    std::shared_ptr<Command> move_up_command;
    std::shared_ptr<Command> move_left_command;
    std::shared_ptr<Command> move_right_command;

    std::shared_ptr<Notification> update_display_data_notification;

    std::shared_ptr<Notification> update_view_notification;

    std::shared_ptr<BRAVER> Braver;
    std::shared_ptr<FLOOR*> Tower;
public:
    ViewModel();
    void bind(std::shared_ptr<Model> model);
    void notified();
    void set_update_view_notification(std::shared_ptr<Notification> notification);
    std::shared_ptr<Notification> get_update_display_data_notification();
    void exec_dialog_command(int x);
    void exec_door_open_command();
    void exec_fight_command(int hp, int exp, int gold);
    void exec_floor_change_command();
    void exec_pick_key_command();
    void exec_pick_item_command();
    void exec_move_down_command();
    void exec_move_up_command();
    void exec_move_left_command();
    void exec_move_right_command();
    std::shared_ptr<Command> get_dialog_command();
    std::shared_ptr<Command> get_door_open_command();
    std::shared_ptr<Command> get_fight_command();
    std::shared_ptr<Command> get_floor_change_command();
    std::shared_ptr<Command> get_pick_key_command();
    std::shared_ptr<Command> get_pick_item_command();
    std::shared_ptr<Command> get_move_down_command();
    std::shared_ptr<Command> get_move_up_command();
    std::shared_ptr<Command> get_move_left_command();
    std::shared_ptr<Command> get_move_right_command();
    std::shared_ptr<BRAVER> get_braver();
    std::shared_ptr<FLOOR*> get_tower();
    void set_braver(std::shared_ptr<BRAVER> x);
    void set_tower(std::shared_ptr<FLOOR*> x);
};

class UpdateDisplayDataNotification: public Notification{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    UpdateDisplayDataNotification(std::shared_ptr<ViewModel> vm):viewmodel(vm){}
    void exec(){
        viewmodel->notified();
    }
};

#endif // VIEWMODEL_H
