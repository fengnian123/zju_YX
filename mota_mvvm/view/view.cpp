#include <QPixmap>
#include "view.h"
#include <QImage>
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
    display_it = 0;
    opendoor_it = 0;
    updown_it = 0;
    fight_period_it = 0;
    fight_end_it = 0;
    gain_item_it = 0;
    OpenDoorTargetPos = -1;
    OpenDoorTempData = -1;
    FightTargetPos = -1;
    OldFloor = 0;
    keyUpCnt = 100;
    scene_b = new QGraphicsScene;
    scene_floor = new QGraphicsScene;
    voice_floor_change=new QSoundEffect;
    voice_bgm=new QSoundEffect;
    voice_door_open=new QSoundEffect;
    voice_fight=new QSoundEffect;
    voice_key_pick=new QSoundEffect;
    voice_item_pick=new QSoundEffect;
    pixmap_items = new QGraphicsPixmapItem*[X * Y];
    update_view_notification = std::static_pointer_cast<Notification, UpdateViewNotification>(std::shared_ptr<UpdateViewNotification>(new UpdateViewNotification(std::shared_ptr<View>(this))));
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

void View::GameStart()
{
    Vars = GLOBAL_VARS();
    LoadImageBeforeGame();
    InitGraphics();
    DisplayData();
    DisplayFloor(Braver->floor);
}

void View::update(){
    std::cout << Braver->pos_x << " " << Braver->pos_y << std::endl;
    DisplayData();
    DisplayFloor(Braver->floor);
}

void View::set_fight_command(std::shared_ptr<Command> command)
{
    fight_command = command;
}
void View::set_pick_key_command(std::shared_ptr<Command> command)
{
    pick_key_command = command;
}
void View::set_pick_item_command(std::shared_ptr<Command> command)
{
    pick_item_command = command;
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

void View::set_move_down_command(std::shared_ptr<Command> command)
{
    move_down_command = command;
}

void View::set_move_up_command(std::shared_ptr<Command> command)
{
    move_up_command = command;
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

void View::set_braver(std::shared_ptr<BRAVER> x){
    Braver = x;
}

void View::set_tower(std::shared_ptr<FLOOR*> x){
    Tower = x;
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
    //背景音乐
    voice_bgm->setSource(QUrl::fromLocalFile(":/music/bgm.wav"));
    voice_bgm->setLoopCount(QSoundEffect::Infinite);
    voice_bgm->setVolume(1.0);
    voice_bgm->play();
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
//    NormalTimer = new QTimer(this);
//    OpenDoorTimer = new QTimer(this);
//    CutTimer = new QTimer(this);
//    FightTimer = new QTimer(this);
//    GainItemTimer = new QTimer(this);
//    connect(NormalTimer, SIGNAL(timeout()), this, SLOT(OnNormalTimerTriggered()));
//    connect(OpenDoorTimer, SIGNAL(timeout()), this, SLOT(OnOpenDoorTimerTriggered()));
//    connect(CutTimer, SIGNAL(timeout()), this, SLOT(OnCutTimerTriggered()));
//    connect(FightTimer, SIGNAL(timeout()), this, SLOT(OnFightTimerTriggered()));
//    connect(GainItemTimer, SIGNAL(timeout()), this, SLOT(OnGainItemTimerTriggered()));
}
void View::DisplayData()
{
//    switch(Braver.status)
//    {
//    case 0:
//        ui->label_8->setText(QString::fromWCharArray(L"正常"));
//        break;
//    default:
//        ui->label_8->setText(QString::fromWCharArray(L"正常"));
//    }
    ui->label_9->setText(QString::number(Braver->level));
    ui->label_10->setText(QString::number(Braver->hp));
    ui->label_11->setText(QString::number(Braver->atk));
    ui->label_12->setText(QString::number(Braver->pdef));
    ui->label_13->setText(QString::number(Braver->exp));
    ui->label_7->setText(QString::number(Braver->key1));
    ui->label_14->setText(QString::number(Braver->key2));
    ui->label_15->setText(QString::number(Braver->key3));
    ui->label_16->setText(QString::number(Braver->gold));
    ui->label_17->setText(QString::fromWCharArray(L"第 ") + QString::number(Braver->floor + 1) + QString::fromWCharArray(L" 层"));
}

void View::DisplayFloor(int floor)
{
    int x, y;
    int item_it = 0;
    scene_floor->clear();
    for(y = 0; y <= 10; y++){
        for(x = 0; x <= 10; x++){
            if (Braver->pos_x == x && Braver->pos_y == y)
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                if (keyUpCnt <= 1)
                    pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgBraver[Braver->face][1]));
                else
                    pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgBraver[Braver->face][0]));
                pixmap_items[item_it]->setPos(QPointF(32 * x, 32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 0 && y * Braver->pos_x + x == OpenDoorTargetPos)
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
            else if ((*Tower)[floor][y * X + x] == 1) //墙
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgWall));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 11 || (*Tower)[floor][y * X + x] == 12) //下楼
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgDownstairs));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 10 || (*Tower)[floor][y * X + x] == 14) //上楼
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgUpstairs));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 21) //门
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgYDoor[0]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 22) //门
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgBDoor[0]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 23) //门
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgRDoor[0]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 24) //门
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgGDoor[0]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 25) //门
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgIDoor[0]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 26) //门
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgFalseWall[0]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 31) //黄钥匙
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgYKey));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 32) //蓝钥匙
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgBKey));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 33) //红钥匙
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgRKey));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 34) //小血瓶
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgBottle1));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 35) //大血瓶
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgBottle2));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 36) //红宝石
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgRGem));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 37) //蓝宝石
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgBGem));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 38) //铁剑
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgSword));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 39) //铁盾
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgShield));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 41) //商店左端
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgStoreLeft));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 42) //商店中间
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgStoreMiddle[display_it]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 43) //商店右端
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgStoreRight));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 45 || (*Tower)[floor][y * X + x] == 48 || (*Tower)[floor][y * X + x] == 50) //NPC
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgNpcRed[display_it]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 46) //NPC
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgNpcThief[display_it]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] == 47 || (*Tower)[floor][y * X + x] == 49 || (*Tower)[floor][y * X + x] == 44) //NPC
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgNpcOld[display_it]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if ((*Tower)[floor][y * X + x] >= 51 && (*Tower)[floor][y * X + x] <= 50 + MONSTER_NUM) //怪物
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgMonsters[(*Tower)[floor][y * X + x] - 51][display_it]));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
        }
    }
    ui->graphicsView_8->setScene(scene_floor);
}

//void View::OnNormalTimerTriggered()
//{
//    keyUpCnt += 1;
//    if (display_it <= 2)
//        display_it += 1;
//    else
//        display_it = 0;
//    DisplayData();
//    DisplayFloor(Braver.floor);
//}

//void View::OnOpenDoorTimerTriggered()
//{
//    if (opendoor_it <= 2)
//    {
//        opendoor_it += 1;
//        DisplayFloor(Braver.floor);
//    }
//    else { //开门已经结束
//        opendoor_it = 0;
//        OpenDoorTargetPos = -1;
//        OpenDoorTempData = -1;
//        Vars.OperationStatus = 0;
//        OpenDoorTimer->stop();
//        DisplayFloor(Braver.floor);
//    }
//}

//void View::OnCutTimerTriggered()
//{
//    if (Vars.CutInFloor3 == false)
//    {
//        if (updown_it <= 3)
//        {
//            updown_it += 1;
//            ui->graphicsView_9->setStyleSheet("background-color:rgba(0,0,0," + QString::number(updown_it * 64) + ");");
//            DisplayFloor(OldFloor);
//        }else if (updown_it <= 7){
//            DisplayData();
//            updown_it += 1;
//            ui->graphicsView_9->setStyleSheet("background-color:rgba(0,0,0," + QString::number((8 - updown_it) * 64) + ");");
//            DisplayFloor(Braver.floor);
//        }else {
//            updown_it = 0;
//            Vars.OperationStatus = 0;
//            CutTimer->stop();
//            ui->graphicsView_9->setStyleSheet("background-color:rgba(0,0,0,0);");
//            DisplayFloor(Braver.floor);
//            NormalTimer->start(200);
//        }
//    }else{
//        if (updown_it <= 3)
//        {
//            updown_it += 1;
//            ui->graphicsView_9->setStyleSheet("background-color:rgba(0,0,0," + QString::number(updown_it * 64) + ");");
//            DisplayFloor(2);
//        }
//        else if (updown_it <= 7){
//            updown_it += 1;
//        }else if (updown_it == 8){
//            CutTimer->stop();
//            QMessageBox::about(this, "Hint", QString::fromStdWString(L" ----- 喂！醒醒！"));
//            Tower[2][6 * X + 4] = 0;
//            Tower[2][7 * X + 4] = 0;
//            Tower[2][8 * X + 3] = 0;
//            Tower[2][8 * X + 4] = 0;
//            Tower[2][8 * X + 5] = 0;
//            Tower[2][9 * X + 4] = 0;
//            Braver.floor = 1;
//            Braver.pos_x = 2;
//            Braver.pos_y = 7;
//            CutTimer->start();
//            updown_it += 1;
//        }else if (updown_it <= 12){
//            DisplayData();
//            updown_it += 1;
//            ui->graphicsView_9->setStyleSheet("background-color:rgba(0,0,0," + QString::number((13 - updown_it) * 64) + ");");
//            DisplayFloor(Braver.floor);
//        }else {
//            updown_it = 0;
//            Vars.OperationStatus = 0;
//            CutTimer->stop();
//            ui->graphicsView_9->setStyleSheet("background-color:rgba(0,0,0,0);");
//            DisplayFloor(Braver.floor);
//            Vars.CutInFloor3 = false;
//            NormalTimer->start(200);
//        }
//    }
//}

//void View::OnFightTimerTriggered()
//{
//    if (fight_period_it == 0)
//    {
//        //准备战斗界面
//        ui->label_20->setText(QString::number(Monster[MonsterIDTemp].hp));
//        ui->label_22->setText(QString::number(Monster[MonsterIDTemp].atk));
//        ui->label_24->setText(QString::number(Monster[MonsterIDTemp].pdef));
//        ui->label_31->setText(QString::number(Braver.hp));
//        ui->label_32->setText(QString::number(Braver.atk));
//        ui->label_33->setText(QString::number(Braver.pdef));

//        ui->label_18->show();
//        ui->label_19->show();
//        ui->label_20->show();
//        ui->label_21->show();
//        ui->label_22->show();
//        ui->label_23->show();
//        ui->label_24->show();
//        ui->label_25->show();
//        ui->label_27->show();
//        ui->label_28->show();
//        ui->label_29->show();
//        ui->label_30->show();
//        ui->label_31->show();
//        ui->label_32->show();
//        ui->label_33->show();
//        ui->graphicsView_10->show();

//        scene_m = new QGraphicsScene;
//        scene_m->addPixmap(QPixmap::fromImage(ImgMonsters[MonsterIDTemp][0]));
//        ui->graphicsView_11->setScene(scene_m);
//        ui->graphicsView_11->show();
//        ui->graphicsView_11->setStyleSheet("background:transparent;border:none;");

//        ui->graphicsView_12->show();

//        fight_period_it = 1;
//    }else if (fight_period_it % 2 == 1 && fight_end_it == 0)
//    {
//        if (Monster[MonsterIDTemp].hp - (Braver.atk - Monster[MonsterIDTemp].pdef) * (fight_period_it / 2 + 1) <= 0)
//        {
//            ui->label_20->setText(QString::number(0));
//            fight_end_it = 1;
//        }else{
//            ui->label_20->setText(QString::number(Monster[MonsterIDTemp].hp - (Braver.atk - Monster[MonsterIDTemp].pdef) * (fight_period_it / 2 + 1)));
//            fight_period_it++;
//        }
//    }else if (fight_period_it % 2 == 0 && fight_end_it == 0)
//    {
//        if (Monster[MonsterIDTemp].atk > Braver.pdef)
//        {
//            ui->label_31->setText(QString::number(Braver.hp - (Monster[MonsterIDTemp].atk - Braver.pdef) * (fight_period_it / 2)));
//        }
//        fight_period_it++;
//    }else{
//        if (fight_end_it <= 2){
//            ui->label_26->show();
//            fight_end_it++;
//        }
//        else if(fight_end_it == 3){
//            //结算战斗结果
//            int damage=0 ;//之后改
//            Braver.hp -= damage;
//            Braver.gold += Monster[MonsterIDTemp].gold;
//            Braver.exp += Monster[MonsterIDTemp].exp;
//            Tower[Braver.floor][FightTargetPos] = 0;
//            //隐藏战斗界面
//            HideFightWindow();
//            ui->label_34->setText(QString::fromWCharArray(L"获得经验值 ") + QString::number(Monster[MonsterIDTemp].exp) + QString::fromWCharArray(L" 金币 ") + QString::number(Monster[MonsterIDTemp].gold));
//            ui->label_34->show();
//            DisplayData();
//            fight_end_it++;
//        }
//        else if (fight_end_it <= 5)
//        {
//            fight_end_it++;
//        }else{
//            FightTimer->stop();
//            ui->label_34->hide();
//            fight_end_it = 0;
//            fight_period_it = 0;
//            MonsterIDTemp = 0;
//            Vars.OperationStatus = 0;
//            delete scene_m;
//        }
//    }
//}

//void View::OnGainItemTimerTriggered()
//{
//    if (gain_item_it == 0)
//    {
//        ui->label_34->setText(QString::fromStdWString(Vars.gain_item_msg));
//        ui->label_34->show();
//        gain_item_it++;
//    }
//    else if (gain_item_it <= 2)
//    {
//        gain_item_it++;
//    }
//    else
//    {
//        GainItemTimer->stop();
//        ui->label_34->hide();
//        gain_item_it = 0;
//        Vars.OperationStatus = 0;

//    }
//}

void View::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){ //向上
        keyUpCnt = 0;
        move_up_command->exec();
    }
    if(event->key() == Qt::Key_Down){ //向下
        keyUpCnt = 0;
        move_down_command->exec();
    }
    if(event->key() == Qt::Key_Left){ //向左
        keyUpCnt = 0;
        move_left_command->exec();
    }
    if(event->key() == Qt::Key_Right){ //向右
        keyUpCnt = 0;
        move_right_command->exec();
    }
    if((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 31 || (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 32 || (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 33){
        //捡钥匙背景音乐
        voice_key_pick->setSource(QUrl::fromLocalFile(":/music/gain-thing.wav"));
        voice_key_pick->setLoopCount(1);
        voice_key_pick->setVolume(5.0f);
        voice_key_pick->play();
        pick_key_command->exec();
    }
    if((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 21 || (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 22 || (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 23){
        //开门背景音乐
        voice_door_open->setSource(QUrl::fromLocalFile(":/music/door-open.wav"));
        voice_door_open->setLoopCount(1);
        voice_door_open->setVolume(5.0f);
        voice_door_open->play();
        door_open_command->exec();
    }
    if((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 10 || (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 11 || (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 12 || (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 14){
        voice_item_pick->setSource(QUrl::fromLocalFile(":/music/floor-change.wav"));
        voice_item_pick->setLoopCount(1);
        voice_item_pick->setVolume(5.0f);
        voice_item_pick->play();
        floor_change_command->exec();
    }
    if((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 34 || (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 35 || (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 36 || (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 37 || (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 38 || (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 39){
        //捡东西背景音乐
        voice_key_pick->setSource(QUrl::fromLocalFile(":/music/gain-yao.wav"));
        voice_key_pick->setLoopCount(1);
        voice_key_pick->setVolume(5.0f);
        voice_key_pick->play();
        pick_key_command->exec();
        pick_item_command->exec();
    }
}

void View::init_monsters(){
    Monster[0].name = L"绿色史莱姆";
    Monster[0].hp = 35;
    Monster[0].atk = 18;
    Monster[0].pdef = 1;
    Monster[0].boss = false;
    Monster[0].attrib = 0;
    Monster[0].gold = 1;
    Monster[0].exp = 0;
    Monster[0].img = ":/Graphics/Characters/003-Monster01.png";
    Monster[0].img_y = 0;

    Monster[1].name = L"红色史莱姆";
    Monster[1].hp = 45;
    Monster[1].atk = 20;
    Monster[1].pdef = 2;
    Monster[1].boss = false;
    Monster[1].attrib = 0;
    Monster[1].gold = 2;
    Monster[1].exp = 0;
    Monster[1].img = ":/Graphics/Characters/003-Monster01.png";
    Monster[1].img_y = 32;

    Monster[2].name = L"骷髅士兵";
    Monster[2].hp = 55;
    Monster[2].atk = 52;
    Monster[2].pdef = 12;
    Monster[2].boss = false;
    Monster[2].attrib = 0;
    Monster[2].gold = 8;
    Monster[2].exp = 0;
    Monster[2].img = ":/Graphics/Characters/005-Monster03.png";
    Monster[2].img_y = 32;

    Monster[3].name = L"骷髅人";
    Monster[3].hp = 50;
    Monster[3].atk = 42;
    Monster[3].pdef = 6;
    Monster[3].boss = false;
    Monster[3].attrib = 0;
    Monster[3].gold = 6;
    Monster[3].exp = 0;
    Monster[3].img = ":/Graphics/Characters/005-Monster03.png";
    Monster[3].img_y = 0;

    Monster[4].name = L"小蝙蝠";
    Monster[4].hp = 35;
    Monster[4].atk = 38;
    Monster[4].pdef = 3;
    Monster[4].boss = false;
    Monster[4].attrib = 0;
    Monster[4].gold = 3;
    Monster[4].exp = 0;
    Monster[4].img = ":/Graphics/Characters/004-Monster02.png";
    Monster[4].img_y = 0;

    Monster[5].name = L"初级法师";
    Monster[5].hp = 60;
    Monster[5].atk = 32;
    Monster[5].pdef = 8;
    Monster[5].boss = false;
    Monster[5].attrib = 0;
    Monster[5].gold = 5;
    Monster[5].exp = 0;
    Monster[5].img = ":/Graphics/Characters/007-Monster05.png";
    Monster[5].img_y = 0;

    Monster[6].name = L"中级卫兵";
    Monster[6].hp = 100;
    Monster[6].atk = 180;
    Monster[6].pdef = 110;
    Monster[6].boss = false;
    Monster[6].attrib = 0;
    Monster[6].gold = 50;
    Monster[6].exp = 0;
    Monster[6].img = ":/Graphics/Characters/008-Monster06.png";
    Monster[6].img_y = 32;

    Monster[7].name = L"初级卫兵";
    Monster[7].hp = 50;
    Monster[7].atk = 48;
    Monster[7].pdef = 22;
    Monster[7].boss = false;
    Monster[7].attrib = 0;
    Monster[7].gold = 12;
    Monster[7].exp = 0;
    Monster[7].img = ":/Graphics/Characters/008-Monster06.png";
    Monster[7].img_y = 0;

    Monster[8].name = L"骷髅队长";
    Monster[8].hp = 100;
    Monster[8].atk = 65;
    Monster[8].pdef = 15;
    Monster[8].boss = false;
    Monster[8].attrib = 0;
    Monster[8].gold = 30;
    Monster[8].exp = 0;
    Monster[8].img = ":/Graphics/Characters/005-Monster03.png";
    Monster[8].img_y = 64;

    Monster[9].name = L"魔法警卫";
    Monster[9].hp = 230;
    Monster[9].atk = 450;
    Monster[9].pdef = 100;
    Monster[9].boss = false;
    Monster[9].attrib = 0;
    Monster[9].gold = 100;
    Monster[9].exp = 0;
    Monster[9].img = ":/Graphics/Characters/010-Monster08.png";
    Monster[9].img_y = 32;

    Monster[10].name = L"假魔王";
    Monster[10].hp = 5000;
    Monster[10].atk = 1580;
    Monster[10].pdef = 190;
    Monster[10].boss = false;
    Monster[10].attrib = 0;
    Monster[10].gold = 0;
    Monster[10].exp = 0;
    Monster[10].img = ":/Graphics/Characters/010-Monster08.png";
    Monster[10].img_y = 0;
}

//void View::init_tower(){
//    FLOOR tmpfloor_1 = {
//        10, 0, 51, 52, 51, 0, 0, 0, 0, 0, 0,
//        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
//        34, 0, 0, 21, 0, 1, 36, 31, 0, 1, 0,
//        0, 54, 0, 1, 0, 1, 37, 34, 0, 1, 0,
//        1, 21, 1, 1, 0, 1, 1, 1, 21, 1, 0,
//        31, 0, 0, 1, 0, 21, 55, 56, 55, 1, 0,
//        0, 53, 0, 1, 0, 1, 1, 1, 1, 1, 0,
//        1, 21, 1, 1, 0, 0, 0, 0, 0, 0, 0,
//        0, 0, 0, 1, 1, 21, 1, 1, 1, 21, 1,
//        34, 0, 31, 1, 31, 0, 0, 1, 0, 55, 0,
//        34, 0, 31, 1, 0, 0, 0, 1, 31, 35, 31,
//    };
//    memcpy((*Tower)[0], tmpfloor_1, sizeof(int) * X * Y);

//    FLOOR tmpfloor_2 = {
//        11, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0,
//        0, 0, 1, 1, 0, 57, 0, 57, 0, 1, 1,
//        0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
//        0, 1, 31, 31, 1, 0, 0, 0, 1, 0, 44,
//        0, 1, 31, 0, 25, 0, 0, 0, 25, 0, 0,
//        0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
//        0, 1, 46, 0, 1, 0, 0, 0, 1, 0, 45,
//        0, 1, 0, 0, 25, 0, 0, 0, 25, 0, 0,
//        0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
//        0, 1, 35, 35, 1, 0, 0, 0, 1, 0, 0,
//        10, 1, 35, 0, 25, 0, 0, 0, 25, 0, 0,
//    };
//    memcpy((*Tower)[1], tmpfloor_2, sizeof(int) * X * Y);

//    FLOOR tmpfloor_3 = {
//        31, 37, 1, 31, 35, 31, 1, 0, 1, 0, 35,
//        0, 34, 1, 35, 31, 35, 1, 0, 21, 55, 0,
//        56, 0, 1, 31, 32, 31, 1, 0, 1, 1, 1,
//        21, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0,
//        0, 0, 55, 0, 0, 0, 51, 0, 0, 0, 0,
//        21, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1,
//        54, 0, 1, 1, 0, 1, 1, 0, 1, 0, 34,
//        0, 31, 1, 0, 0, 0, 1, 0, 21, 56, 31,
//        34, 36, 1, 0, 13, 0, 1, 0, 1, 1, 1,
//        1, 1, 1, 1, 0, 1, 1, 52, 1, 0, 0,
//        11, 0, 0, 0, 0, 0, 1, 0, 21, 0, 10,
//    };
//    memcpy((*Tower)[2], tmpfloor_3, sizeof(int) * X * Y);

//    FLOOR tmpfloor_4 = {
//        0, 32, 0, 1, 41, 42, 43, 1, 0, 47, 0,
//        34, 0, 31, 1, 0, 0, 0, 1, 31, 0, 35,
//        0, 0, 0, 1, 0, 0, 0, 1, 0, 53, 0,
//        1, 21, 1, 1, 1, 22, 1, 1, 1, 21, 1,
//        0, 55, 0, 21, 0, 52, 0, 0, 54, 0, 0,
//        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
//        52, 0, 51, 0, 0, 0, 0, 0, 0, 0, 0,
//        21, 1, 1, 21, 1, 1, 1, 21, 1, 1, 21,
//        0, 1, 0, 55, 0, 1, 0, 56, 0, 1, 0,
//        0, 1, 51, 0, 31, 1, 36, 0, 34, 1, 0,
//        10, 1, 31, 51, 31, 1, 0, 51, 0, 1, 11,
//    };
//    memcpy((*Tower)[3], tmpfloor_4, sizeof(int) * X * Y);

//    FLOOR tmpfloor_5 = {
//        10, 1, 0, 52, 21, 0, 1, 0, 0, 21, 0,
//        0, 1, 0, 0, 1, 31, 1, 51, 51, 1, 52,
//        0, 21, 55, 0, 1, 0, 1, 31, 31, 1, 0,
//        1, 1, 1, 21, 1, 55, 1, 31, 31, 1, 0,
//        31, 0, 56, 0, 1, 0, 1, 1, 1, 1, 0,
//        31, 0, 0, 55, 1, 0, 51, 0, 0, 0, 0,
//        1, 53, 1, 1, 1, 0, 1, 1, 1, 1, 52,
//        0, 0, 0, 0, 1, 51, 1, 0, 0, 0, 0,
//        37, 31, 34, 0, 1, 0, 1, 21, 1, 1, 1,
//        1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0,
//        11, 0, 0, 0, 0, 0, 1, 0, 26, 0, 38,
//    };
//    memcpy((*Tower)[4], tmpfloor_5, sizeof(int) * X * Y);

//    FLOOR tmpfloor_6 = {
//        11, 1, 31, 31, 1, 0, 56, 0, 31, 51, 0,
//        0, 1, 31, 31, 1, 0, 1, 1, 1, 1, 21,
//        0, 1, 1, 52, 1, 0, 1, 34, 0, 54, 0,
//        0, 21, 21, 0, 21, 0, 1, 48, 0, 0, 55,
//        0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
//        0, 0, 52, 56, 0, 0, 0, 54, 53, 0, 0,
//        1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0,
//        56, 0, 0, 49, 1, 0, 21, 21, 0, 21, 0,
//        0, 55, 0, 37, 1, 0, 1, 1, 52, 1, 52,
//        21, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0,
//        0, 51, 0, 0, 54, 0, 1, 34, 34, 1, 10,
//    };
//    memcpy((*Tower)[5], tmpfloor_6, sizeof(int) * X * Y);

//    FLOOR tmpfloor_7 = {
//        10, 1, 36, 1, 0, 50, 0, 1, 31, 1, 51,
//        0, 1, 34, 1, 0, 0, 0, 1, 31, 1, 52,
//        0, 1, 55, 1, 52, 1, 53, 1, 34, 1, 51,
//        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
//        21, 1, 21, 1, 22, 1, 21, 1, 54, 1, 21,
//        0, 53, 0, 56, 0, 0, 0, 0, 0, 0, 0,
//        21, 1, 21, 1, 21, 1, 21, 1, 53, 1, 21,
//        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
//        0, 1, 0, 1, 55, 1, 52, 1, 35, 1, 0,
//        51, 1, 51, 1, 31, 1, 56, 1, 31, 1, 0,
//        0, 52, 0, 1, 31, 1, 35, 1, 31, 1, 11,
//    };
//    memcpy((*Tower)[6], tmpfloor_7, sizeof(int) * X * Y);

//    FLOOR tmpfloor_8 = {
//        11, 0, 21, 21, 0, 10, 0, 1, 31, 0, 31,
//        0, 0, 1, 1, 0, 0, 51, 1, 0, 33, 0,
//        21, 1, 1, 1, 1, 21, 1, 1, 35, 0, 34,
//        0, 1, 31, 31, 31, 0, 0, 1, 1, 24, 1,
//        34, 1, 1, 1, 1, 1, 56, 1, 58, 0, 58,
//        0, 52, 51, 52, 0, 1, 0, 1, 0, 0, 0,
//        1, 1, 1, 1, 21, 1, 55, 1, 1, 21, 1,
//        0, 0, 0, 55, 0, 54, 0, 56, 0, 0, 0,
//        21, 1, 1, 1, 1, 1, 1, 1, 1, 1, 21,
//        51, 0, 1, 36, 31, 1, 32, 34, 1, 0, 54,
//        0, 55, 22, 31, 37, 1, 31, 0, 21, 53, 0,
//    };
//    memcpy((*Tower)[7], tmpfloor_8, sizeof(int) * X * Y);

//    FLOOR tmpfloor_9 = {
//        0, 0, 54, 21, 0, 11, 0, 21, 51, 0, 34,
//        0, 31, 0, 1, 0, 0, 0, 1, 0, 51, 0,
//        53, 1, 1, 1, 1, 22, 1, 1, 1, 1, 0,
//        0, 31, 0, 1, 31, 0, 31, 21, 21, 0, 0,
//        37, 0, 55, 21, 0, 36, 0, 1, 1, 26, 1,
//        1, 1, 1, 1, 1, 1, 52, 1, 0, 0, 53,
//        31, 0, 21, 53, 31, 1, 0, 1, 39, 1, 0,
//        53, 0, 1, 0, 0, 1, 0, 1, 1, 1, 21,
//        21, 1, 1, 1, 21, 1, 0, 1, 31, 0, 56,
//        0, 34, 1, 0, 54, 1, 55, 1, 0, 54, 0,
//        10, 0, 22, 0, 0, 21, 0, 21, 56, 0, 34,
//    };
//    memcpy((*Tower)[8], tmpfloor_9, sizeof(int) * X * Y);

//    FLOOR tmpfloor_10 = {
//        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//        1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
//        54, 54, 54, 1, 1, 0, 1, 1, 54, 54, 54,
//        0, 53, 0, 24, 0, 59, 0, 24, 0, 53, 0,
//        1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
//        54, 37, 54, 1, 1, 0, 1, 1, 54, 36, 54,
//        0, 53, 0, 1, 1, 0, 1, 1, 0, 53, 0,
//        0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0,
//        21, 1, 21, 1, 1, 23, 1, 1, 21, 1, 21,
//        0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0,
//        11, 1, 0, 56, 0, 14, 0, 56, 0, 1, 35,
//    };
//    memcpy((*Tower)[9], tmpfloor_10, sizeof(int) * X * Y);
//}
