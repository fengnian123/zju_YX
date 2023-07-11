#ifndef MOVE_RIGHT_COMMAND_H
#define MOVE_RIGHT_COMMAND_H

#include "command/command.h"
#include <memory>
class ViewModel;
class MoveRightCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    MoveRightCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
