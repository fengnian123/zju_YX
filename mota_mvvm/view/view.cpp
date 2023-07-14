#include <QPixmap>
#include "view.h"
#include <QImage>
#include "ui_view.h"
#include <QTimer>
#include <QMessageBox>
#include "notification/notification.h"
#include "ui_storewindow.h"
#include <QGraphicsPixmapItem>
#include "StoreWindow.h"
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
    in_store=0;
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
    wstore = new StoreWindow;
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
            ImgMonsters[t0][t1] = QImage((*Monster)[t0].img.c_str()).copy(t1 * 32, (*Monster)[t0].img_y, 32, 32);
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
    if (Vars.OperationStatus == 0){
        in_store = 0;
        DisplayData();
        DisplayFloor(Braver->floor);
    }

    else if (Vars.OperationStatus == 3)
    { //正在开门 播放开门动画之后恢复为正常情况
        OpenDoorTimer->start(50);
        OpenDoorTargetPos = target_pos;
        OpenDoorTempData = old_data;
        DisplayFloor(Braver->floor);
    }
    else if (Vars.OperationStatus == 4)
    {
        // 上下楼转场
        NormalTimer->stop();
        CutTimer->start(50);
    }
    else if (Vars.OperationStatus == 5){
        //战斗
        DisplayData();
        FightTargetPos = target_pos;
        FightTimer->start(100);
    }else if (Vars.OperationStatus == 7){
        scene_store = new QGraphicsScene;
        scene_store->addPixmap(QPixmap::fromImage(ImgStoreMiddle[0]));
        wstore->ui->graphicsView->setScene(scene_store);
        wstore->ui->graphicsView->setStyleSheet("background:transparent;border:none;");
        wstore->ui->label->setText(QString::fromStdWString(L"商店") );
        wstore->ui->label_3->setText(QString::fromStdWString(L"提升 800 点生命"));
        wstore->ui->label_4->setText(QString::fromStdWString(L"提升 4 点攻击力"));
        wstore->ui->label_5->setText(QString::fromStdWString(L"提升 4 点防御力"));
        wstore->ui->label_6->setText(QString::fromStdWString(L"离开商店"));
        wstore->choice_num = 4;
        wstore->target_pos = target_pos;
        wstore->OpenStore(&Vars);
        wstore->show();
    }
}

StoreWindow* View::get_wstore(){
    return wstore;
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
void View::set_floor_change_command(std::shared_ptr<Command> command)
{
    floor_change_command = command;
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

void View::set_monster(std::shared_ptr<MONSTER*> x){
    Monster = x;
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
            if ((*Tower)[floor][y * X + x] == 0 && y * X + x == OpenDoorTargetPos)
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
            else if (((*Tower)[floor][y * X + x] == 11 || (*Tower)[floor][y * X + x] == 12) && !(Braver->pos_x == x && Braver->pos_y == y)) //下楼
            {
                pixmap_items[item_it] = new QGraphicsPixmapItem;
                pixmap_items[item_it]->setPixmap(QPixmap::fromImage(ImgDownstairs));
                pixmap_items[item_it]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[item_it]);
                item_it++;
            }
            else if (((*Tower)[floor][y * X + x] == 10 || (*Tower)[floor][y * X + x] == 14) && !(Braver->pos_x == x && Braver->pos_y == y)) //上楼
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

void View::OnNormalTimerTriggered()
{
    keyUpCnt += 1;
    if (display_it <= 2)
        display_it += 1;
    else
        display_it = 0;
    DisplayData();
    DisplayFloor(Braver->floor);
}

void View::OnOpenDoorTimerTriggered()
{
    if (opendoor_it <= 2)
    {
        opendoor_it += 1;
        DisplayFloor(Braver->floor);
    }
    else { //开门已经结束
        opendoor_it = 0;
        OpenDoorTargetPos = -1;
        OpenDoorTempData = -1;
        Vars.OperationStatus = 0;
        OpenDoorTimer->stop();
        DisplayFloor(Braver->floor);
    }
}

void View::OnCutTimerTriggered()
{
    if (1)
    {
        if (updown_it <= 3)
        {
            updown_it += 1;
            ui->graphicsView_9->setStyleSheet("background-color:rgba(0,0,0," + QString::number(updown_it * 64) + ");");
            //DisplayFloor(OldFloor);
        }else if (updown_it <= 7){
            DisplayData();
            updown_it += 1;
            ui->graphicsView_9->setStyleSheet("background-color:rgba(0,0,0," + QString::number((8 - updown_it) * 64) + ");");
            DisplayFloor(Braver->floor);
        }else {
            updown_it = 0;
            Vars.OperationStatus = 0;
            CutTimer->stop();
            ui->graphicsView_9->setStyleSheet("background-color:rgba(0,0,0,0);");
            DisplayFloor(Braver->floor);
            NormalTimer->start(200);
        }
    }
}

void View::OnFightTimerTriggered()
{
    if (fight_period_it == 0)
    {
        Braver->hp += ((*Monster)[MonsterIDTemp].hp-1) / (Braver->atk - (*Monster)[MonsterIDTemp].pdef) * ((*Monster)[MonsterIDTemp].atk - Braver->pdef);
        //准备战斗界面
        ui->label_20->setText(QString::number((*Monster)[MonsterIDTemp].hp));
        ui->label_22->setText(QString::number((*Monster)[MonsterIDTemp].atk));
        ui->label_24->setText(QString::number((*Monster)[MonsterIDTemp].pdef));
        ui->label_31->setText(QString::number(Braver->hp));
        ui->label_32->setText(QString::number(Braver->atk));
        ui->label_33->setText(QString::number(Braver->pdef));

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
        if ((*Monster)[MonsterIDTemp].hp - (Braver->atk - (*Monster)[MonsterIDTemp].pdef) * (fight_period_it / 2 + 1) <= 0)
        {
            ui->label_20->setText(QString::number(0));
            fight_end_it = 1;
        }else{
            ui->label_20->setText(QString::number((*Monster)[MonsterIDTemp].hp - (Braver->atk - (*Monster)[MonsterIDTemp].pdef) * (fight_period_it / 2 + 1)));
            fight_period_it++;
        }
    }else if (fight_period_it % 2 == 0 && fight_end_it == 0)
    {
        if ((*Monster)[MonsterIDTemp].atk > Braver->pdef)
        {
            ui->label_31->setText(QString::number(Braver->hp - ((*Monster)[MonsterIDTemp].atk - Braver->pdef) * (fight_period_it / 2)));
        }
        fight_period_it++;
    }else{
        if (fight_end_it <= 2){
            //ui->label_26->show();
            fight_end_it++;
        }
        else if(fight_end_it == 3){
            //隐藏战斗界面
            HideFightWindow();
            ui->label_34->setText(QString::fromWCharArray(L"获得经验值 ") + QString::number((*Monster)[MonsterIDTemp].exp) + QString::fromWCharArray(L" 金币 ") + QString::number((*Monster)[MonsterIDTemp].gold));
            ui->label_34->show();
            Braver->hp -= ((*Monster)[MonsterIDTemp].hp-1) / (Braver->atk - (*Monster)[MonsterIDTemp].pdef) * ((*Monster)[MonsterIDTemp].atk - Braver->pdef);
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

}
int ct=0;
void View::keyPressEvent(QKeyEvent *event)
{
    target_pos = -1;
    old_data =-1;
    if(event->key() == Qt::Key_Up && Vars.OperationStatus == 0){ //向上
        keyUpCnt = 0;
        Vars.OperationStatus = handle_keypress(1, target_pos, old_data);
        if (Vars.OperationStatus == 3){
            voice_door_open->setSource(QUrl::fromLocalFile(":/music/door-open.wav"));
            voice_door_open->setLoopCount(1);
            voice_door_open->setVolume(5.0f);
            voice_door_open->play();
        }
        move_up_command->exec();
    }
    if(event->key() == Qt::Key_Down && Vars.OperationStatus == 0){ //向下
        keyUpCnt = 0;
        Vars.OperationStatus = handle_keypress(3, target_pos, old_data);
        if (Vars.OperationStatus == 3){
            voice_door_open->setSource(QUrl::fromLocalFile(":/music/door-open.wav"));
            voice_door_open->setLoopCount(1);
            voice_door_open->setVolume(5.0f);
            voice_door_open->play();
        }
        move_down_command->exec();
    }
    if(event->key() == Qt::Key_Left && Vars.OperationStatus == 0){ //向左
        keyUpCnt = 0;
        Vars.OperationStatus = handle_keypress(0, target_pos, old_data);
        if (Vars.OperationStatus == 3){
            voice_door_open->setSource(QUrl::fromLocalFile(":/music/door-open.wav"));
            voice_door_open->setLoopCount(1);
            voice_door_open->setVolume(5.0f);
            voice_door_open->play();
        }
        move_left_command->exec();
    }
    if(event->key() == Qt::Key_Right && Vars.OperationStatus == 0){ //向右
        keyUpCnt = 0;
        Vars.OperationStatus = handle_keypress(2, target_pos, old_data);
        if (Vars.OperationStatus == 3){
            voice_door_open->setSource(QUrl::fromLocalFile(":/music/door-open.wav"));
            voice_door_open->setLoopCount(1);
            voice_door_open->setVolume(5.0f);
            voice_door_open->play();
        }
        move_right_command->exec();
    }
    if((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 31 || (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 32 || (*Tower)[Braver->floor][Braver->pos_y+1 * X + Braver->pos_x] == 33){
        //捡钥匙背景音乐
        voice_key_pick->setSource(QUrl::fromLocalFile(":/music/gain-thing.wav"));
        voice_key_pick->setLoopCount(1);
        voice_key_pick->setVolume(5.0f);
        voice_key_pick->play();
        pick_key_command->exec();
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
        pick_item_command->exec();
    }
    if((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] >= 51 && (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] <= 50 + MONSTER_NUM){
        Vars.OperationStatus = 5;
        //战斗背景音乐
        MonsterIDTemp = (*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] - 51;
        int times = (*Monster)[MonsterIDTemp].hp / (Braver->atk - (*Monster)[MonsterIDTemp].pdef);
        voice_fight->setSource(QUrl::fromLocalFile(":/music/fight.wav"));
        voice_fight->setLoopCount(times+1);
        voice_fight->setVolume(5.0f);
        voice_fight->play();
        fight_command->exec();
    }
    if((*Tower)[Braver->floor][Braver->pos_y * X + Braver->pos_x] == 42){
        Vars.OperationStatus = 7;
        //商店背景音乐
    }
}

int View::handle_keypress(int key_no, int& target_pos, int& old_data)
{
    // 返回操作状态。0为可以操作，1为对话框模式，2为已经game_over, 3为正在开门中, 4为上下楼转场, 5为打开自动战斗画面, 6为打开获得物品界面, 7为开启商店处理, 8为三层被打的转场，9为怪物手册处理
    // 首先找出要移动的目标位置.如果超出了地图范围，则直接返回
    old_data = -1;
    if (key_no == 0) { //向左
        if (Braver->pos_x == 0)
            return 0;
        else
            target_pos = Braver->pos_y * X + (Braver->pos_x - 1);
    }else if (key_no == 1){ //向上
        if (Braver->pos_y == 0)
            return 0;
        else
            target_pos = (Braver->pos_y - 1) * X + Braver->pos_x;
    }else if (key_no == 2){ //向右
        if (Braver->pos_x == X - 1)
            return 0;
        else
            target_pos = Braver->pos_y * X + (Braver->pos_x + 1);
    }else if (key_no == 3){ //向下
        if (Braver->pos_y == Y - 1)
            return 0;
        else
            target_pos = (Braver->pos_y + 1) * X + Braver->pos_x;
    }else{
        return 0;
    }
    old_data = (*Tower)[Braver->floor][target_pos];
    if ((*Tower)[Braver->floor][target_pos] == 0){ //平地 直接走过去
        return 0;
    }
    else if (((*Tower)[Braver->floor][target_pos] >= 1 && (*Tower)[Braver->floor][target_pos] <= 9) || (*Tower)[Braver->floor][target_pos] == 41 || (*Tower)[Braver->floor][target_pos] == 43){ //撞墙 位置不变化
        return 0;
    }else if ((*Tower)[Braver->floor][target_pos] == 12){
        //触发结局一：离开。直接Game Over
        Vars.end_no = 1;
        Vars.dialog_no = 1;
        //show_dialog();
        return 1;
    }else if ((*Tower)[Braver->floor][target_pos] == 13){
        //3层被打的转场
//        Braver->pos_x = target_pos % X;
//        Braver->pos_y = target_pos / X;
//        (*Tower)[2][6 * X + 4] = 61;
//        (*Tower)[2][7 * X + 4] = 60;
//        (*Tower)[2][8 * X + 3] = 60;
//        (*Tower)[2][8 * X + 5] = 60;
//        (*Tower)[2][9 * X + 4] = 60;
//        Vars.CutInFloor3 = true;
//        return 8;
    }else if ((*Tower)[Braver->floor][target_pos] == 14){
        Vars.hint_msg = L"11层之后的内容，还未制作完成。";
//        return 1;
    }else if ((*Tower)[Braver->floor][target_pos] == 21){
        //黄门
        return 3;
    }else if ((*Tower)[Braver->floor][target_pos] == 22){
        //蓝门
        return 3;
    }else if ((*Tower)[Braver->floor][target_pos] == 23){
        //红门
        return 3;
    }else if ((*Tower)[Braver->floor][target_pos] == 24){
        //绿门
        return 3;
    }else if ((*Tower)[Braver->floor][target_pos] == 25){
        //铁门
        return 3;
    }else if ((*Tower)[Braver->floor][target_pos] == 26){
        //暗墙
        return 3;
    }else if ((*Tower)[Braver->floor][target_pos] == 10 || (*Tower)[Braver->floor][target_pos] == 11){
        //上下楼
        return 4;
    }else if ((*Tower)[Braver->floor][target_pos] == 42){
        //商店处理
//        Vars.store_no = 1;
        return 7;
    }else if ((*Tower)[Braver->floor][target_pos] == 44){
//        Vars.hint_msg = L"谢谢你救了我，\n为了感谢你的帮助请收下这些礼物.\n（收到1000金币）";
//        Braver->gold += 1000;
        return 1;
    }else if ((*Tower)[Braver->floor][target_pos] == 45){
        //商人处理
//        Vars.store_no = 2;
        return 7;
    }else if ((*Tower)[Braver->floor][target_pos] == 46){
        //盗贼处理
//        if (target_pos == 6 * X + 2)
//            Vars.hint_msg = L"你清醒了吗？你到监狱时还处在昏迷中，\n魔法警卫把你扔到我这个房间。但你很幸运，\n我刚完成逃跑的暗道你就醒了，我们一起越狱吧。";
//        else
//            Vars.hint_msg = L"我们终于逃出来了。你的剑和盾被警卫拿走了，\n你必须先找到武器。我知道铁剑在5楼，铁盾在9楼，\n你最好先取得它们。我现在有事要做没法帮你，再见。";
        return 1;
    }else if ((*Tower)[Braver->floor][target_pos] == 47){
        Vars.hint_msg = L"有些门不能用钥匙打开。\n只有当你打败它的守卫后才会自动打开。";
        return 1;
    }else if ((*Tower)[Braver->floor][target_pos] == 48){
        //商人处理
        if (Vars.BuyKeyInFloor6 == true)
        {
            Vars.hint_msg = L"魔塔一共50层，每10层为一个区域。\n如果不打败此区域的头目\n就不能到更高的地方";
            return 1;
        }
        else
        {
            Vars.store_no = 3;
            return 7;
        }
    }else if ((*Tower)[Braver->floor][target_pos] == 49){
        Vars.hint_msg = L"你购买了礼物后再与商人对话，\n他会告诉你一些重要的消息。";
        return 1;
    }else if ((*Tower)[Braver->floor][target_pos] == 50){
        //商人处理
        if (Vars.BuyKeyInFloor7 == true)
        {
            Vars.hint_msg = L"在商店里你最好选择提升防御，\n只有在攻击力低于敌人的防御力时才提升攻击力。";
            return 1;
        }
        else
        {
            Vars.store_no = 4;
            return 7;
        }
    }else if ((*Tower)[Braver->floor][target_pos] >= 51){
        //怪物
        int monster_id = (*Tower)[Braver->floor][target_pos] - 51;
        int damage = 0;
        if (damage == -2){
            //在打不过时，不进行任何处理
            Vars.hint_msg = L"你还不能打败他";
            return 1;
        }else if (damage == -1 || damage >= Braver->hp){
            //在打不过时，不进行任何处理
            Vars.hint_msg = L"你还不能打败他";
            return 1;
        }else{
            //Braver->hp -= damage;
            //Braver->gold += Monster[monster_id].gold;
            //Braver->exp += Monster[monster_id].exp;
            //Tower[Braver->floor][target_pos] = 0;
            if (monster_id == 6)
                Vars.OpenFloor2DoorCnt += 1;
            if (monster_id == 7)
                Vars.OpenFloor8DoorCnt += 1;
            //return 5;
        }
    }
    return 0;
}


