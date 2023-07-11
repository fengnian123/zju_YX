#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <memory>

class Notification
{
public:
    Notification();
    virtual void exec() = 0;
};

#endif // NOTIFICATION_H
