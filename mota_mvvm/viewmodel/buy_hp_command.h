#ifndef BUY_HP_COMMAND_H
#define BUY_HP_COMMAND_H

#include "command/command.h"
#include <memory>
class ViewModel;
class BuyHpCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    BuyHpCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
