#ifndef MOVE_UP_COMMAND_H
#define MOVE_UP_COMMAND_H

#include "command/command.h"
#include <memory>
class ViewModel;
class MoveUpCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    MoveUpCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
