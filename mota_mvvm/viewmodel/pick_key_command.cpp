#include "pick_key_command.h"
#include "viewmodel/viewmodel.h"

void PickKeyCommand::exec(){
    viewmodel->exec_pick_key_command();
}
