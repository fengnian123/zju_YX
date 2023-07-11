#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <memory>


class Command
{
protected:
public:
    Command() {}
    virtual void exec() = 0;
};

#endif // COMMAND_H
