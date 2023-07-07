#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "variables/variables.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);
    ~View();

    void LoadImageBeforeGame();
private:
    Ui::MainWindow *ui;

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
};
#endif // MAINWINDOW_H
