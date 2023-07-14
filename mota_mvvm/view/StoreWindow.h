#ifndef STOREWINDOW_H
#define STOREWINDOW_H
#include <QWidget>
#include <memory>
#include <QTimer>
#include <QDebug>
#include <QSoundEffect>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QWheelEvent>
#include "command/command.h"
using namespace std;

class GLOBAL_VARS;

namespace Ui {
class StoreWindow;
}

class StoreWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StoreWindow(QWidget *parent = nullptr);
    ~StoreWindow();

    void Init();
    void OpenStore(GLOBAL_VARS* Vars);
    void handle_store(int choice_no, int target_pos);
    int choice_num; //有多少个选项
    int target_pos; //商店在楼层中的位置
    GLOBAL_VARS* Vars;
    Ui::StoreWindow *ui;

    void set_buy_atk_command(std::shared_ptr<Command>);
    void set_buy_def_command(std::shared_ptr<Command>);
    void set_buy_hp_command(std::shared_ptr<Command>);

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    QSoundEffect *voice_store;
    int border_color_it;
    int choose_no; //选择了第几项

    std::shared_ptr<Command> buy_atk_command;
    std::shared_ptr<Command> buy_def_command;
    std::shared_ptr<Command> buy_hp_command;

    const string BorderColor[6] = {"FFFFFF", "CCCCCC", "999999", "666666", "999999", "CCCCCC"};
    QTimer* BorderColorTimer;

public slots:
    void OnColorTimerTriggered();
};

//extern StoreWindow* wstore;
#endif // STOREWINDOW_H
