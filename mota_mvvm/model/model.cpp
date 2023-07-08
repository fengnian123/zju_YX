#include <iostream>
#include <string>
#include "notification/notification.h"
using namespace std;

void Model::set_update_display_data_notification(std::shared_ptr<Notification> notification)
{
    this->update_display_data_notification = notification;
}

void Model::notify(){
    update_display_data_notification->exec();
}
