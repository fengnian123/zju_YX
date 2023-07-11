#ifndef DIALOG_COMMAND_H
#define DIALOG_COMMAND_H

#include "command/command.h"
#include <memory>
class ViewModel;
class DialogCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    DialogCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
