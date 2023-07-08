#include "app.h"
#include "view/view.h"
#include "viewmodel/viewmodel.h"
#include "model/model.h"
#include "command/command.h"
#include "notification/notification.h"
#include <memory>

App::App() : view(new View), model(new Model), viewmodel(new ViewModel)
{
    viewmodel->bind(model);

    view->set_fight_command(viewmodel->get_fight_command());
    view->set_pick_key_command(viewmodel->get_pick_key_command());
    view->set_door_open_command(viewmodel->get_door_open_command());
    view->set_floor_change_command(viewmodel->get_floor_change_command());
    view->set_dialog_command(viewmodel->get_dialog_command());
    view->set_move_up_command(viewmodel->get_move_up_command());
    view->set_move_down_command(viewmodel->get_move_down_command());
    view->set_move_left_command(viewmodel->get_move_left_command());
    view->set_move_right_command(viewmodel->get_move_right_command());

    viewmodel->set_update_view_notification(view->get_update_view_notification());
    model->set_update_display_data_notification(viewmodel->get_update_display_data_notification());
    view->GameStart();
}

void App::run(){
    view->show();
}
