#include "move_left_command.h"
#include "viewmodel/viewmodel.h"

void MoveLeftCommand::exec(){
    viewmodel->exec_move_left_command();
}
