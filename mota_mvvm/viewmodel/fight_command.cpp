#include "fight_command.h"
#include "viewmodel/viewmodel.h"

void FightCommand::exec(){
    viewmodel->exec_fight_command();
}
