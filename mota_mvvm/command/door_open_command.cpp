#include "door_open_command.h"
#include "viewmodel/viewmodel.h"

void DoorOpenCommand::exec(){
    viewmodel->exec_door_open_command();
}
