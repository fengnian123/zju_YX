#include "app.h"
#include "view/view.h"
#include "viewmodel/viewmodel.h"
#include "model/model.h"
#include "command/command.h"
#include "notification/notification.h"
#include <memory>

App::App() : view(new View), model(new Model), viewmodel(new ViewModel)
{
    //test
}

void App::run(){
    view->show();
}

void App::Init(){

}
