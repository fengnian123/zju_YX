#ifndef DIALOG_COMMAND_H
#define DIALOG_COMMAND_H

#include "command.h"
#include <memory>

class DialogCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    DialogCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
