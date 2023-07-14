#ifndef BUY_DEF_COMMAND_H
#define BUY_DEF_COMMAND_H

#include "command/command.h"
#include <memory>
class ViewModel;
class BuyDefCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    BuyDefCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
