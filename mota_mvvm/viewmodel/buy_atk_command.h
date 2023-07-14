#ifndef BUY_ATK_COMMAND_H
#define BUY_ATK_COMMAND_H

#include "command/command.h"
#include <memory>
class ViewModel;
class BuyAtkCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    BuyAtkCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
