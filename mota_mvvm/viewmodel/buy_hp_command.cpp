#include "buy_hp_command.h"
#include "viewmodel/viewmodel.h"

void BuyHpCommand::exec(){
    viewmodel->exec_buy_hp_command();
}
