#include "pick_item_command.h"
#include "viewmodel/viewmodel.h"

void PickItemCommand::exec(){
    viewmodel->exec_pick_item_command();
}
