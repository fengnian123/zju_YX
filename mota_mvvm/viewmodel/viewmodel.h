#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include "model/model.h"
#include <memory>
#include "command/command.h"

class Model;
class Notification;
class ViewModelNotification;
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
};

#endif // VIEWMODEL_H
