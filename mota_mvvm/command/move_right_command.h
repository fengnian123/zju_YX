#ifndef MOVE_RIGHT_COMMAND_H
#define MOVE_RIGHT_COMMAND_H

#include "command.h"
#include "viewmodel/viewmodel.h"
#include <memory>

class MoveRightCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    MoveRightCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
