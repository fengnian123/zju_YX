#ifndef PICK_KEY_COMMAND_H
#define PICK_KEY_COMMAND_H

#include "command.h"
#include "viewmodel/viewmodel.h"
#include <memory>

class PickKeyCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    PickKeyCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
