#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include <QImage>
#include <memory>
#include "command/command.h"

class Model;
class Notification;
class ViewModelNotification;
class Command;

class ViewModel
{
private:

public:

    void notified();
};

#endif // VIEWMODEL_H
