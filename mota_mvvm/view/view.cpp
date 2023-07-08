#include <QPixmap>
#include "view.h"
#include <QImage>
#include "variables/variables.h"
#include "ui_view.h"
#include <QTimer>
#include <QMessageBox>
#include "notification/notification.h"
#include <QGraphicsPixmapItem>
View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
}

void View::LoadImageBeforeGame()
{
    ImgWall = QImage(":/Graphics/Tilesets/Mota.png").copy(192, 0, 32, 32);
    ImgUpstairs = QImage(":/Graphics/Tilesets/Mota.png").copy(32, 992, 32, 32);
    ImgDownstairs = QImage(":/Graphics/Tilesets/Mota.png").copy(0, 992, 32, 32);
    ImgYKey = QImage(":/Graphics/Characters/item01.png").copy(0, 0, 32, 32);
    ImgBKey = QImage(":/Graphics/Characters/item01.png").copy(32, 0, 32, 32);
    ImgRKey = QImage(":/Graphics/Characters/item01.png").copy(64, 0, 32, 32);
    ImgBottle1 = QImage(":/Graphics/Characters/item03.png").copy(0, 32, 32, 32);
    ImgBottle2 = QImage(":/Graphics/Characters/item03.png").copy(32, 32, 32, 32);
    ImgRGem = QImage(":/Graphics/Characters/item03.png").copy(0, 0, 32, 32);
    ImgBGem = QImage(":/Graphics/Characters/item03.png").copy(32, 0, 32, 32);
    ImgSword = QImage(":/Graphics/Characters/item04.png").copy(0, 0, 32, 32);
    ImgShield = QImage(":/Graphics/Characters/item04.png").copy(0, 64, 32, 32);
    ImgStoreLeft = QImage(":/Graphics/Tilesets/Mota.png").copy(96, 992, 32, 32);
    ImgStoreRight = QImage(":/Graphics/Tilesets/Mota.png").copy(160, 992, 32, 32);
    for (int t = 0; t <= 3; t++)
        ImgStoreMiddle[t] = QImage(":/Graphics/Characters/001-npc02.png").copy(32 * t, 64, 32, 32);
    for (int t = 0; t <= 3; t++)
    {
        ImgYDoor[t] = QImage(":/Graphics/Characters/men001.png").copy(0, 32 * t, 32, 32);
        ImgBDoor[t] = QImage(":/Graphics/Characters/men001.png").copy(32, 32 * t, 32, 32);
        ImgRDoor[t] = QImage(":/Graphics/Characters/men001.png").copy(64, 32 * t, 32, 32);
        ImgGDoor[t] = QImage(":/Graphics/Characters/men001.png").copy(96, 32 * t, 32, 32);
        ImgIDoor[t] = QImage(":/Graphics/Characters/men002.png").copy(96, 32 * t, 32, 32);
        ImgFalseWall[t] = QImage(":/Graphics/Characters/men002.png").copy(32, 32 * t, 32, 32);
        ImgNpcOld[t] = QImage(":/Graphics/Characters/001-npc01.png").copy(32 * t, 0, 32, 32);
        ImgNpcRed[t] = QImage(":/Graphics/Characters/001-npc01.png").copy(32 * t, 32, 32, 32);
        ImgNpcThief[t] = QImage(":/Graphics/Characters/001-npc01.png").copy(32 * t, 64, 32, 32);
    }
    for (int t = 0; t <= 3; t++)
    {
        ImgBraver[t][0] = QImage(":/Graphics/Characters/002-Braver01.png").copy(0, t * 32, 32, 32);
        ImgBraver[t][1] = QImage(":/Graphics/Characters/002-Braver01.png").copy(32, t * 32, 32, 32);
    }
    for (int t0 = 0; t0 <= MONSTER_NUM - 1; t0++){
        for (int t1 = 0; t1 <= 3; t1++){
            ImgMonsters[t0][t1] = QImage(Monster[t0].img.c_str()).copy(t1 * 32, Monster[t0].img_y, 32, 32);
        }
    }
}

View::~View()
{
    delete ui;
}

void View::set_fight_command(std::shared_ptr<Command> command)
{
    fight_command = command;
}
void View::set_pick_key_command(std::shared_ptr<Command> command)
{
    pick_key_command = command;
}
void View::set_door_open_command(std::shared_ptr<Command> command)
{
    door_open_command = command;
}
void View::set_floor_change_command(std::shared_ptr<Command> command)
{
    floor_change_command = command;
}
void View::set_dialog_command(std::shared_ptr<Command> command)
{
    dialog_command = command;
}
void View::set_move_up_command(std::shared_ptr<Command> command)
{
    move_up_command = command;
}
void View::set_move_down_command(std::shared_ptr<Command> command)
{
    move_down_command = command;
}
void View::set_move_left_command(std::shared_ptr<Command> command)
{
    move_left_command = command;
}
void View::set_move_right_command(std::shared_ptr<Command> command)
{
    move_right_command = command;
}
std::shared_ptr<Notification> View::get_update_view_notification(){
    return update_view_notification;
}

void View::HideFightWindow()
{
    ui->graphicsView_10->hide();
    ui->graphicsView_11->hide();
    ui->graphicsView_12->hide();

    ui->label_18->hide();
    ui->label_19->hide();
    ui->label_20->hide();
    ui->label_21->hide();
    ui->label_22->hide();
    ui->label_23->hide();
    ui->label_24->hide();
    ui->label_25->hide();
    ui->label_26->hide();
    ui->label_27->hide();
    ui->label_28->hide();
    ui->label_29->hide();
    ui->label_30->hide();
    ui->label_31->hide();
    ui->label_32->hide();
    ui->label_33->hide();
    ui->label_34->hide();
}

void View::InitGraphics()
{
    //窗口大小为固定值，不可以更改
    this->setFixedSize(576, 416);
    this->setFocusPolicy(Qt::StrongFocus);

    //首先画背景。背景为深蓝色砖块
    QImage img_background = QImage(":/Graphics/Tilesets/Mota.png").copy(160, 0, 32, 32);
    QPalette palette;
    palette.setBrush(QPalette::Window, QPixmap::fromImage(img_background));
    this->setPalette(palette);

    //绘制游戏界面内的下图层。
    QImage img_llayer = QImage(":/Graphics/Tilesets/Mota.png").copy(96, 32, 32, 32);
    QGraphicsScene *scene_llayer = new QGraphicsScene;
    scene_llayer->setBackgroundBrush(QPixmap::fromImage(img_llayer));
    ui->graphicsView_7->setScene(scene_llayer);
    //QObject::connect(scene_llayer, SIGNAL(sceneRectChanged(QRectF)), this, SLOT(sceneRectChanged(QRectF)));

    //上图层graphicsView8背景透明 对齐方式靠左靠上
    ui->graphicsView_8->setStyleSheet("background:transparent;");
    ui->graphicsView_8->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView_8->setFocusPolicy(Qt::NoFocus);

    //初始化物品栏
    QGraphicsScene *scene_ykey = new QGraphicsScene;
    scene_ykey->addPixmap(QPixmap::fromImage(ImgYKey));
    ui->graphicsView_3->setScene(scene_ykey);
    ui->graphicsView_3->setStyleSheet("background:transparent;border:none;");

    QGraphicsScene *scene_bkey = new QGraphicsScene;
    scene_bkey->addPixmap(QPixmap::fromImage(ImgBKey));
    ui->graphicsView_4->setScene(scene_bkey);
    ui->graphicsView_4->setStyleSheet("background:transparent;border:none;");

    QGraphicsScene *scene_rkey = new QGraphicsScene;
    scene_rkey->addPixmap(QPixmap::fromImage(ImgRKey));
    ui->graphicsView_5->setScene(scene_rkey);
    ui->graphicsView_5->setStyleSheet("background:transparent;border:none;");

    QGraphicsScene *scene_gold = new QGraphicsScene;
    scene_gold->addPixmap(QPixmap::fromImage(QImage(":/Graphics/Characters/item01.png").copy(96, 96, 32, 32)));
    ui->graphicsView_6->setScene(scene_gold);
    ui->graphicsView_6->setStyleSheet("background:transparent;border:none;");

    //第x层的背景为黑色
    ui->label_17->setStyleSheet("background-color:rgba(0,0,0,255);");

    //黑色覆盖用于转场动画。默认不显示
    ui->graphicsView_9->setStyleSheet("background-color:rgba(0,0,0,0);");
    ui->graphicsView_9->setFocusPolicy(Qt::NoFocus);
    ui->listWidget->hide();

    //战斗界面中勇者的图标
    scene_b->addPixmap(QPixmap::fromImage(ImgBraver[0][0]));
    ui->graphicsView_12->setScene(scene_b);
    ui->graphicsView_12->setStyleSheet("background:transparent;border:none;");

    //不显示战斗界面
    //    ui->graphicsView_10->setScene(scene_llayer);
    ui->graphicsView_10->setFocusPolicy(Qt::NoFocus);
    ui->graphicsView_11->setFocusPolicy(Qt::NoFocus);
    ui->graphicsView_12->setFocusPolicy(Qt::NoFocus);
    ui->label_34->setStyleSheet("background-color:rgba(0,0,0,255);");
    HideFightWindow();

    //初始化定时器。用于展示动态效果
    NormalTimer = new QTimer(this);
    OpenDoorTimer = new QTimer(this);
    CutTimer = new QTimer(this);
    FightTimer = new QTimer(this);
    GainItemTimer = new QTimer(this);
    connect(NormalTimer, SIGNAL(timeout()), this, SLOT(OnNormalTimerTriggered()));
    connect(OpenDoorTimer, SIGNAL(timeout()), this, SLOT(OnOpenDoorTimerTriggered()));
    connect(CutTimer, SIGNAL(timeout()), this, SLOT(OnCutTimerTriggered()));
    connect(FightTimer, SIGNAL(timeout()), this, SLOT(OnFightTimerTriggered()));
    connect(GainItemTimer, SIGNAL(timeout()), this, SLOT(OnGainItemTimerTriggered()));
}
void View::DisplayData()
{
    switch(Braver.status)
    {
    case 0:
        ui->label_8->setText(QString::fromWCharArray(L"正常"));
        break;
    default:
        ui->label_8->setText(QString::fromWCharArray(L"正常"));
    }
    ui->label_9->setText(QString::number(Braver.level));
    ui->label_10->setText(QString::number(Braver.hp));
    ui->label_11->setText(QString::number(Braver.atk));
    ui->label_12->setText(QString::number(Braver.pdef));
    ui->label_13->setText(QString::number(Braver.exp));
    ui->label_7->setText(QString::number(Braver.key1));
    ui->label_14->setText(QString::number(Braver.key2));
    ui->label_15->setText(QString::number(Braver.key3));
    ui->label_16->setText(QString::number(Braver.gold));
    ui->label_17->setText(QString::fromWCharArray(L"第 ") + QString::number(Braver.floor + 1) + QString::fromWCharArray(L" 层"));
}

void View::DisplayFloor(int floor)
{
    int x, y;
    int item_it = 0;
    scene_floor->clear();
    for(y = 0; y <= 10; y++){
        for(x = 0; x <= 10; x++){
            if (View::x == x && View::y == y)
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                if (keyUpCnt <= 1)
                    pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgBraver[Braver.face][1]));
                else
                    pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgBraver[Braver.face][0]));
                pixmap_items[item_it]->setPos(QPointF(32 * x, 32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 0 && y * View::x + x == OpenDoorTargetPos)
            {
                if (OpenDoorTempData == 21) //正在被打开的黄门
                {
                    pixmap_items[item_it] = new QGraphicsPixmapItem;
                    pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgYDoor[opendoor_it]));
                    pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                    scene_floor->addItem(pixmap_items[item_it]);
                    item_it++;
                }
                if (OpenDoorTempData == 22) //正在被打开的蓝门
                {
                    pixmap_items[item_it] = new QGraphicsPixmapItem;
                    pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgBDoor[opendoor_it]));
                    pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                    scene_floor->addItem(pixmap_items[item_it]);
                    item_it++;
                }
                if (OpenDoorTempData == 23) //正在被打开的红门
                {
                    pixmap_items[item_it] = new QGraphicsPixmapItem;
                    pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgRDoor[opendoor_it]));
                    pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                    scene_floor->addItem(pixmap_items[item_it]);
                    item_it++;
                }
                if (OpenDoorTempData == 24) //正在被打开的绿门
                {
                    pixmap_items[item_it] = new QGraphicsPixmapItem;
                    pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgGDoor[opendoor_it]));
                    pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                    scene_floor->addItem(pixmap_items[item_it]);
                    item_it++;
                }
                if (OpenDoorTempData == 25) //正在被打开的铁门
                {
                    pixmap_items[item_it] = new QGraphicsPixmapItem;
                    pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgIDoor[opendoor_it]));
                    pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                    scene_floor->addItem(pixmap_items[item_it]);
                    item_it++;
                }
                if (OpenDoorTempData == 26) //正在被打开的暗墙
                {
                    pixmap_items[item_it] = new QGraphicsPixmapItem;
                    pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgFalseWall[opendoor_it]));
                    pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                    scene_floor->addItem(pixmap_items[item_it]);
                    item_it++;
                }
            }
            else if (Tower[floor][y * View::x + x] == 1) //墙
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgWall));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 11 || Tower[floor][y * View::x + x] == 12) //下楼
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgDownstairs));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 10 || Tower[floor][y * View::x + x] == 14) //上楼
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgUpstairs));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 21) //门
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgYDoor[0]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 22) //门
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgBDoor[0]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 23) //门
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgRDoor[0]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 24) //门
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgGDoor[0]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 25) //门
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgIDoor[0]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 26) //门
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgFalseWall[0]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 31) //黄钥匙
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgYKey));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 32) //蓝钥匙
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgBKey));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 33) //红钥匙
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgRKey));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * X + x] == 34) //小血瓶
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgBottle1));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 35) //大血瓶
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgBottle2));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 36) //红宝石
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgRGem));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 37) //蓝钥匙
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgBGem));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 38) //铁剑
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgSword));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 39) //铁盾
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgShield));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * X + x] == 41) //商店左端
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgStoreLeft));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 42) //商店中间
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgStoreMiddle[display_it]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 43) //商店右端
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgStoreRight));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 45 || Tower[floor][y * X + x] == 48 || Tower[floor][y * X + x] == 50) //NPC
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgNpcRed[display_it]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 46) //NPC
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgNpcThief[display_it]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] == 47 || Tower[floor][y * View::x + x] == 49 || Tower[floor][y * View::x + x] == 44) //NPC
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgNpcOld[display_it]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (Tower[floor][y * View::x + x] >= 51 && Tower[floor][y * View::x + x] <= 50 + MONSTER_NUM) //怪物
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgMonsters[Tower[floor][y * X + x] - 51][display_it]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
        }
    }
    ui->graphicsView_8->setScene(scene_floor);
}

void View::OnNormalTimerTriggered()
{
    keyUpCnt += 1;
    if (display_it <= 2)
        display_it += 1;
    else
        display_it = 0;
    DisplayData();
    DisplayFloor(Braver.floor);
}

void View::OnOpenDoorTimerTriggered()
{
    if (opendoor_it <= 2)
    {
        opendoor_it += 1;
        DisplayFloor(Braver.floor);
    }
    else { //开门已经结束
        opendoor_it = 0;
        OpenDoorTargetPos = -1;
        OpenDoorTempData = -1;
        Vars.OperationStatus = 0;
        OpenDoorTimer->stop();
        DisplayFloor(Braver.floor);
    }
}

void View::OnCutTimerTriggered()
{
    if (Vars.CutInFloor3 == false)
    {
        if (updown_it <= 3)
        {
            updown_it += 1;
            ui->graphicsView_9->setStyleSheet("background-color:rgba(0,0,0," + QString::number(updown_it * 64) + ");");
            DisplayFloor(OldFloor);
        }else if (updown_it <= 7){
            DisplayData();
            updown_it += 1;
            ui->graphicsView_9->setStyleSheet("background-color:rgba(0,0,0," + QString::number((8 - updown_it) * 64) + ");");
            DisplayFloor(Braver.floor);
        }else {
            updown_it = 0;
            Vars.OperationStatus = 0;
            CutTimer->stop();
            ui->graphicsView_9->setStyleSheet("background-color:rgba(0,0,0,0);");
            DisplayFloor(Braver.floor);
            NormalTimer->start(200);
        }
    }else{
        if (updown_it <= 3)
        {
            updown_it += 1;
            ui->graphicsView_9->setStyleSheet("background-color:rgba(0,0,0," + QString::number(updown_it * 64) + ");");
            DisplayFloor(2);
        }
        else if (updown_it <= 7){
            updown_it += 1;
        }else if (updown_it == 8){
            CutTimer->stop();
            QMessageBox::about(this, "Hint", QString::fromStdWString(L" ----- 喂！醒醒！"));
            Tower[2][6 * X + 4] = 0;
            Tower[2][7 * X + 4] = 0;
            Tower[2][8 * X + 3] = 0;
            Tower[2][8 * X + 4] = 0;
            Tower[2][8 * X + 5] = 0;
            Tower[2][9 * X + 4] = 0;
            Braver.floor = 1;
            Braver.pos_x = 2;
            Braver.pos_y = 7;
            CutTimer->start();
            updown_it += 1;
        }else if (updown_it <= 12){
            DisplayData();
            updown_it += 1;
            ui->graphicsView_9->setStyleSheet("background-color:rgba(0,0,0," + QString::number((13 - updown_it) * 64) + ");");
            DisplayFloor(Braver.floor);
        }else {
            updown_it = 0;
            Vars.OperationStatus = 0;
            CutTimer->stop();
            ui->graphicsView_9->setStyleSheet("background-color:rgba(0,0,0,0);");
            DisplayFloor(Braver.floor);
            Vars.CutInFloor3 = false;
            NormalTimer->start(200);
        }
    }
}

void View::OnFightTimerTriggered()
{
    if (fight_period_it == 0)
    {
        //准备战斗界面
        ui->label_20->setText(QString::number(Monster[MonsterIDTemp].hp));
        ui->label_22->setText(QString::number(Monster[MonsterIDTemp].atk));
        ui->label_24->setText(QString::number(Monster[MonsterIDTemp].pdef));
        ui->label_31->setText(QString::number(Braver.hp));
        ui->label_32->setText(QString::number(Braver.atk));
        ui->label_33->setText(QString::number(Braver.pdef));

        ui->label_18->show();
        ui->label_19->show();
        ui->label_20->show();
        ui->label_21->show();
        ui->label_22->show();
        ui->label_23->show();
        ui->label_24->show();
        ui->label_25->show();
        ui->label_27->show();
        ui->label_28->show();
        ui->label_29->show();
        ui->label_30->show();
        ui->label_31->show();
        ui->label_32->show();
        ui->label_33->show();
        ui->graphicsView_10->show();

        scene_m = new QGraphicsScene;
        scene_m->addPixmap(QPixmap::fromImage(ImgMonsters[MonsterIDTemp][0]));
        ui->graphicsView_11->setScene(scene_m);
        ui->graphicsView_11->show();
        ui->graphicsView_11->setStyleSheet("background:transparent;border:none;");

        ui->graphicsView_12->show();

        fight_period_it = 1;
    }else if (fight_period_it % 2 == 1 && fight_end_it == 0)
    {
        if (Monster[MonsterIDTemp].hp - (Braver.atk - Monster[MonsterIDTemp].pdef) * (fight_period_it / 2 + 1) <= 0)
        {
            ui->label_20->setText(QString::number(0));
            fight_end_it = 1;
        }else{
            ui->label_20->setText(QString::number(Monster[MonsterIDTemp].hp - (Braver.atk - Monster[MonsterIDTemp].pdef) * (fight_period_it / 2 + 1)));
            fight_period_it++;
        }
    }else if (fight_period_it % 2 == 0 && fight_end_it == 0)
    {
        if (Monster[MonsterIDTemp].atk > Braver.pdef)
        {
            ui->label_31->setText(QString::number(Braver.hp - (Monster[MonsterIDTemp].atk - Braver.pdef) * (fight_period_it / 2)));
        }
        fight_period_it++;
    }else{
        if (fight_end_it <= 2){
            ui->label_26->show();
            fight_end_it++;
        }
        else if(fight_end_it == 3){
            //结算战斗结果
            int damage=0 ;//之后改
            Braver.hp -= damage;
            Braver.gold += Monster[MonsterIDTemp].gold;
            Braver.exp += Monster[MonsterIDTemp].exp;
            Tower[Braver.floor][FightTargetPos] = 0;
            //隐藏战斗界面
            HideFightWindow();
            ui->label_34->setText(QString::fromWCharArray(L"获得经验值 ") + QString::number(Monster[MonsterIDTemp].exp) + QString::fromWCharArray(L" 金币 ") + QString::number(Monster[MonsterIDTemp].gold));
            ui->label_34->show();
            DisplayData();
            fight_end_it++;
        }
        else if (fight_end_it <= 5)
        {
            fight_end_it++;
        }else{
            FightTimer->stop();
            ui->label_34->hide();
            fight_end_it = 0;
            fight_period_it = 0;
            MonsterIDTemp = 0;
            Vars.OperationStatus = 0;
            delete scene_m;
        }
    }
}

void View::OnGainItemTimerTriggered()
{
    if (gain_item_it == 0)
    {
        ui->label_34->setText(QString::fromStdWString(Vars.gain_item_msg));
        ui->label_34->show();
        gain_item_it++;
    }
    else if (gain_item_it <= 2)
    {
        gain_item_it++;
    }
    else
    {
        GainItemTimer->stop();
        ui->label_34->hide();
        gain_item_it = 0;
        Vars.OperationStatus = 0;

    }
}

void View::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){ //向上
        keyUpCnt = 0;
        View::y++;
        move_up_command->exec();
    }
    if(event->key() == Qt::Key_Down){ //向下
        keyUpCnt = 0;
        View::y--;
        move_down_command->exec();
    }
    if(event->key() == Qt::Key_Left){ //向左
        keyUpCnt = 0;
        View::x--;
        move_left_command->exec();
    }
    if(event->key() == Qt::Key_Right){ //向右
        keyUpCnt = 0;
        View::x++;
        move_right_command->exec();
    }

}
