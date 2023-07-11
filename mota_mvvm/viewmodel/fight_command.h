#ifndef FIGHT_COMMAND_H
#define FIGHT_COMMAND_H

#include "command/command.h"
#include <memory>
class ViewModel;
class FightCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    FightCommand(std::shared_ptr<ViewModel> vm) : viewmodel(vm){}
    void exec();
};

#endif
