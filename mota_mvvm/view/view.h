#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <QImage>
#include <QDebug>
#include <iostream>
#include "command/command.h"
#include <QGraphicsView>
#include <QMouseEvent>
#include <QWheelEvent>
#include "variables/variables.h"
class Notification;
namespace Ui {
class View;
}
class View : public QMainWindow
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);
    ~View();
    void update();
    void set_fight_command(std::shared_ptr<Command>);
    void set_pick_key_command(std::shared_ptr<Command>);
    void set_door_open_command(std::shared_ptr<Command>);
    void set_floor_change_command(std::shared_ptr<Command>);
    void set_dialog_command(std::shared_ptr<Command>);
    void set_move_up_command(std::shared_ptr<Command>);
    void set_move_down_command(std::shared_ptr<Command>);
    void set_move_left_command(std::shared_ptr<Command>);
    void set_move_right_command(std::shared_ptr<Command>);
    void InitGraphics(); //初始化主界面
    void DisplayFloor(int floor); //展示楼层信息
    void DisplayData(); //展示状态数据
    void GameStart(); //游戏内容的初始化
    std::shared_ptr<Notification> get_update_view_notification();

    void LoadImageBeforeGame();
public slots:
    void OnNormalTimerTriggered();
    void OnOpenDoorTimerTriggered();
    void OnCutTimerTriggered();
    void OnFightTimerTriggered();
    void OnGainItemTimerTriggered();
    void HideFightWindow();

protected:
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::View *ui;

    QImage ImgWall;
    QImage ImgUpstairs;
    QImage ImgDownstairs;
    QImage ImgYDoor[4];
    QImage ImgBDoor[4];
    QImage ImgRDoor[4];
    QImage ImgGDoor[4];
    QImage ImgIDoor[4];
    QImage ImgFalseWall[4];
    QImage ImgMonsters[MONSTER_NUM][4];
    QImage ImgBraver[4][2];
    QImage ImgStoreLeft;
    QImage ImgStoreMiddle[4];
    QImage ImgStoreRight;
    QImage ImgYKey;
    QImage ImgBKey;
    QImage ImgRKey;
    QImage ImgBottle1;
    QImage ImgBottle2;
    QImage ImgRGem;
    QImage ImgBGem;
    QImage ImgSword;
    QImage ImgShield;
    QImage ImgNpcOld[4];
    QImage ImgNpcRed[4];
    QImage ImgNpcThief[4];
    int display_it;
    int opendoor_it;
    int updown_it;
    int fight_period_it;
    int fight_end_it;
    int gain_item_it;
    int OpenDoorTargetPos;
    int OpenDoorTempData;
    int FightTargetPos;
    int MonsterIDTemp;
    int OldFloor;
    int keyUpCnt; //按键松开的时间
    int x,y;//位置
    QTimer* NormalTimer; //层内动态效果的定时器
    QTimer* OpenDoorTimer; //播放开门动画的定时器
    QTimer* CutTimer; //转场动画的计时器
    QTimer* FightTimer; //战斗的计时器
    QTimer* GainItemTimer; //获得物品的计时器

    QGraphicsScene *scene_m;
    QGraphicsScene *scene_b;
    QGraphicsScene *scene_store;
    QGraphicsScene *scene_floor;
    QGraphicsPixmapItem **pixmap_items;

    std::shared_ptr<Command> fight_command;
    std::shared_ptr<Command> pick_key_command;
    std::shared_ptr<Command> door_open_command;
    std::shared_ptr<Command> floor_change_command;
    std::shared_ptr<Command> dialog_command;
    std::shared_ptr<Command> move_up_command;
    std::shared_ptr<Command> move_down_command;
    std::shared_ptr<Command> move_left_command;
    std::shared_ptr<Command> move_right_command;
    std::shared_ptr<Notification> update_view_notification;
};
#endif // MAINWINDOW_H
