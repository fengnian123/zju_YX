#ifndef PICK_ITEM_COMMAND_H
#define PICK_ITEM_COMMAND_H

#include "command.h"
#include <memory>

class PickItemCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    PickItemCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
