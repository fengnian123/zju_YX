#include "move_right_command.h"
#include "viewmodel/viewmodel.h"

void MoveRightCommand::exec(){
    viewmodel->exec_move_right_command();
}
