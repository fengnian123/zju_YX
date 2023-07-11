#include "move_up_command.h"
#include "viewmodel/viewmodel.h"

void MoveUpCommand::exec(){
    viewmodel->exec_move_up_command();
}
