#include "buy_def_command.h"
#include "viewmodel/viewmodel.h"

void BuyDefCommand::exec(){
    viewmodel->exec_buy_def_command();
}
