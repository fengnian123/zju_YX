#include "move_down_command.h"
#include "viewmodel/viewmodel.h"

void MoveDownCommand::exec(){
    viewmodel->exec_move_down_command();
}
