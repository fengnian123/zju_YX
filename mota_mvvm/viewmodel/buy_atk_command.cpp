#include "buy_atk_command.h"
#include "viewmodel/viewmodel.h"

void BuyAtkCommand::exec(){
    viewmodel->exec_buy_atk_command();
}
