#ifndef FLOOR_CHANGE_COMMAND_H
#define FLOOR_CHANGE_COMMAND_H

#include "command.h"
#include "viewmodel/viewmodel.h"
#include <memory>

class FloorChangeCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    FloorChangeCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
