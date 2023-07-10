#include "floor_change_command.h"
#include "viewmodel/viewmodel.h"

void FloorChangeCommand::exec(){
    viewmodel->exec_floor_change_command();
}
