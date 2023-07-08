#ifndef MOVE_UP_COMMAND_H
#define MOVE_UP_COMMAND_H

#include "command.h"
#include "viewmodel/viewmodel.h"
#include <memory>

class MoveUpCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    MoveUpCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
