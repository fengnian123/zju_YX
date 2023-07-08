#ifndef MOVE_LEFT_COMMAND_H
#define MOVE_LEFT_COMMAND_H

#include "command.h"
#include "viewmodel/viewmodel.h"
#include <memory>

class MoveLeftCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    MoveLeftCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
