/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QGraphicsView *graphicsView_3;
    QGraphicsView *graphicsView_4;
    QGraphicsView *graphicsView_5;
    QGraphicsView *graphicsView_6;
    QLabel *label_7;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QGraphicsView *graphicsView_7;
    QGraphicsView *graphicsView_8;
    QLabel *label_17;
    QGraphicsView *graphicsView_9;
    QGraphicsView *graphicsView_10;
    QGraphicsView *graphicsView_11;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QGraphicsView *graphicsView_12;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(576, 416);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(48, 16, 144, 192));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        graphicsView->setPalette(palette1);
        graphicsView->setAutoFillBackground(true);
        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName("graphicsView_2");
        graphicsView_2->setGeometry(QRect(48, 240, 144, 128));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        graphicsView_2->setPalette(palette2);
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(48, 16, 60, 20));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush2(QColor(190, 190, 190, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label->setPalette(palette3);
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(48, 48, 60, 20));
        QPalette palette4;
        QBrush brush3(QColor(238, 238, 236, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_2->setPalette(palette4);
        label_2->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(48, 80, 60, 20));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_3->setPalette(palette5);
        label_3->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(48, 112, 60, 20));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_4->setPalette(palette6);
        label_4->setFont(font);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(48, 144, 60, 20));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_5->setPalette(palette7);
        label_5->setFont(font);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(48, 176, 60, 20));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_6->setPalette(palette8);
        label_6->setFont(font);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(108, 16, 80, 20));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_8->setPalette(palette9);
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(108, 48, 80, 20));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_9->setPalette(palette10);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font1.setPointSize(12);
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(108, 80, 80, 20));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_10->setPalette(palette11);
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(108, 112, 80, 20));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_11->setPalette(palette12);
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(108, 144, 80, 20));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_12->setPalette(palette13);
        label_12->setFont(font1);
        label_12->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(108, 176, 80, 20));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_13->setPalette(palette14);
        label_13->setFont(font1);
        label_13->setAlignment(Qt::AlignCenter);
        graphicsView_3 = new QGraphicsView(centralWidget);
        graphicsView_3->setObjectName("graphicsView_3");
        graphicsView_3->setGeometry(QRect(48, 240, 32, 32));
        QPalette palette15;
        QBrush brush4(QColor(191, 64, 64, 0));
        brush4.setStyle(Qt::SolidPattern);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        graphicsView_3->setPalette(palette15);
        graphicsView_4 = new QGraphicsView(centralWidget);
        graphicsView_4->setObjectName("graphicsView_4");
        graphicsView_4->setGeometry(QRect(48, 272, 32, 32));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        graphicsView_4->setPalette(palette16);
        graphicsView_5 = new QGraphicsView(centralWidget);
        graphicsView_5->setObjectName("graphicsView_5");
        graphicsView_5->setGeometry(QRect(48, 304, 32, 32));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        graphicsView_5->setPalette(palette17);
        graphicsView_6 = new QGraphicsView(centralWidget);
        graphicsView_6->setObjectName("graphicsView_6");
        graphicsView_6->setGeometry(QRect(48, 336, 32, 32));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette18.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette18.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette18.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette18.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette18.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        graphicsView_6->setPalette(palette18);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(112, 240, 80, 32));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_7->setPalette(palette19);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font2.setPointSize(18);
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(112, 272, 80, 32));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_14->setPalette(palette20);
        label_14->setFont(font2);
        label_14->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(112, 304, 80, 32));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette21.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_15->setPalette(palette21);
        label_15->setFont(font2);
        label_15->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(112, 336, 80, 32));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_16->setPalette(palette22);
        label_16->setFont(font2);
        label_16->setAlignment(Qt::AlignCenter);
        graphicsView_7 = new QGraphicsView(centralWidget);
        graphicsView_7->setObjectName("graphicsView_7");
        graphicsView_7->setGeometry(QRect(208, 16, 354, 354));
        graphicsView_8 = new QGraphicsView(centralWidget);
        graphicsView_8->setObjectName("graphicsView_8");
        graphicsView_8->setGeometry(QRect(208, 16, 354, 354));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(320, 0, 128, 16));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette23.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_17->setPalette(palette23);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        label_17->setFont(font3);
        label_17->setAlignment(Qt::AlignCenter);
        graphicsView_9 = new QGraphicsView(centralWidget);
        graphicsView_9->setObjectName("graphicsView_9");
        graphicsView_9->setGeometry(QRect(208, 16, 354, 354));
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette24.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette24.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        graphicsView_9->setPalette(palette24);
        graphicsView_10 = new QGraphicsView(centralWidget);
        graphicsView_10->setObjectName("graphicsView_10");
        graphicsView_10->setGeometry(QRect(208, 80, 354, 160));
        QPalette palette25;
        palette25.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette25.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette25.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        graphicsView_10->setPalette(palette25);
        graphicsView_11 = new QGraphicsView(centralWidget);
        graphicsView_11->setObjectName("graphicsView_11");
        graphicsView_11->setGeometry(QRect(224, 112, 32, 32));
        QPalette palette26;
        palette26.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette26.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette26.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        graphicsView_11->setPalette(palette26);
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(208, 160, 64, 20));
        QPalette palette27;
        palette27.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_18->setPalette(palette27);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font4.setPointSize(12);
        font4.setBold(true);
        label_18->setFont(font4);
        label_18->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(272, 96, 64, 26));
        QPalette palette28;
        palette28.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette28.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette28.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_19->setPalette(palette28);
        label_19->setFont(font1);
        label_19->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(304, 120, 50, 20));
        QPalette palette29;
        palette29.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette29.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette29.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_20->setPalette(palette29);
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(272, 144, 64, 26));
        QPalette palette30;
        palette30.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette30.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette30.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_21->setPalette(palette30);
        label_21->setFont(font1);
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(304, 168, 50, 20));
        QPalette palette31;
        palette31.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette31.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_22->setPalette(palette31);
        label_23 = new QLabel(centralWidget);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(272, 192, 64, 26));
        QPalette palette32;
        palette32.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette32.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette32.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_23->setPalette(palette32);
        label_23->setFont(font1);
        label_23->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_24 = new QLabel(centralWidget);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(304, 216, 50, 20));
        QPalette palette33;
        palette33.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette33.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette33.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_24->setPalette(palette33);
        label_25 = new QLabel(centralWidget);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(344, 128, 80, 64));
        QPalette palette34;
        QBrush brush5(QColor(239, 41, 41, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette34.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette34.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette34.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_25->setPalette(palette34);
        QFont font5;
        font5.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font5.setPointSize(30);
        font5.setBold(true);
        label_25->setFont(font5);
        label_25->setAlignment(Qt::AlignCenter);
        label_26 = new QLabel(centralWidget);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(288, 176, 192, 64));
        QPalette palette35;
        palette35.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette35.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette35.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_26->setPalette(palette35);
        QFont font6;
        font6.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267")});
        font6.setPointSize(30);
        font6.setBold(true);
        label_26->setFont(font6);
        label_26->setAlignment(Qt::AlignCenter);
        graphicsView_12 = new QGraphicsView(centralWidget);
        graphicsView_12->setObjectName("graphicsView_12");
        graphicsView_12->setGeometry(QRect(510, 112, 32, 32));
        QPalette palette36;
        palette36.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette36.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette36.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        graphicsView_12->setPalette(palette36);
        label_27 = new QLabel(centralWidget);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(496, 160, 64, 20));
        QPalette palette37;
        palette37.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette37.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette37.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_27->setPalette(palette37);
        label_27->setFont(font4);
        label_27->setAlignment(Qt::AlignCenter);
        label_28 = new QLabel(centralWidget);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(430, 96, 64, 26));
        QPalette palette38;
        palette38.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette38.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette38.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_28->setPalette(palette38);
        label_28->setFont(font1);
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_29 = new QLabel(centralWidget);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(430, 144, 64, 26));
        QPalette palette39;
        palette39.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette39.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette39.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_29->setPalette(palette39);
        label_29->setFont(font1);
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_30 = new QLabel(centralWidget);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(430, 192, 64, 26));
        QPalette palette40;
        palette40.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette40.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette40.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_30->setPalette(palette40);
        label_30->setFont(font1);
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_31 = new QLabel(centralWidget);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(412, 120, 50, 20));
        QPalette palette41;
        palette41.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette41.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette41.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_31->setPalette(palette41);
        label_31->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_32 = new QLabel(centralWidget);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(412, 168, 50, 20));
        QPalette palette42;
        palette42.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette42.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette42.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_32->setPalette(palette42);
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_33 = new QLabel(centralWidget);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(412, 216, 50, 20));
        QPalette palette43;
        palette43.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette43.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette43.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_33->setPalette(palette43);
        label_33->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_34 = new QLabel(centralWidget);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(224, 144, 320, 64));
        QPalette palette44;
        palette44.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette44.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette44.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_34->setPalette(palette44);
        label_34->setFont(font2);
        label_34->setAlignment(Qt::AlignCenter);
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(208, 16, 354, 354));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 576, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\255\211\347\272\247", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\224\237\345\221\275\345\200\274", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\224\273\345\207\273\345\212\233", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\351\230\262\345\276\241\345\212\233", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\347\273\217\351\252\214\345\200\274", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\346\255\243\345\270\270", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "19999", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "1800", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "1200", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\346\200\252\347\211\251", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "<u>\347\224\237\345\221\275\345\200\274</u>", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "<u>\346\224\273\345\207\273\345\212\233</u>", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "<u>\351\230\262\345\276\241\345\212\233</u>", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "VS", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\346\210\230\346\226\227\350\203\234\345\210\251", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\345\213\207\345\243\253", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "<u>\347\224\237\345\221\275\345\200\274</u>", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "<u>\346\224\273\345\207\273\345\212\233</u>", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "<u>\351\230\262\345\276\241\345\212\233</u>", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
