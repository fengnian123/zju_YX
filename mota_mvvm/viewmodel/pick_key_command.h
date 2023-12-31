#ifndef PICK_KEY_COMMAND_H
#define PICK_KEY_COMMAND_H

#include "command/command.h"
#include <memory>
class ViewModel;
class PickKeyCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    PickKeyCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
