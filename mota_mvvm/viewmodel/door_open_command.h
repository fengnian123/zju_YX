#ifndef DOOR_OPEN_COMMAND_H
#define DOOR_OPEN_COMMAND_H

#include "command/command.h"
#include <memory>
class ViewModel;
class DoorOpenCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    DoorOpenCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
