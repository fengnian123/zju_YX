#ifndef MOVE_DOWN_COMMAND_H
#define MOVE_DOWN_COMMAND_H

#include "command.h"
#include <memory>

class MoveDownCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    MoveDownCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
