#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <memory>
class ViewModel;

class Command
{
protected:
public:
    Command();

    //    Parameters& get_params_handle();
    //    void set_view_model(std::shared_ptr<ViewModel> viewmodel);
    virtual void exec() = 0;
};




#endif // COMMAND_H
