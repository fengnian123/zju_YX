#include "view/view.h"
#include "ui_mainwindow.h"

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

