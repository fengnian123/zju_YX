/********************************************************************************
** Form generated from reading UI file 'storewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOREWINDOW_H
#define UI_STOREWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StoreWindow
{
public:
    QGraphicsView *graphicsView;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QGraphicsView *graphicsView_2;
    QLabel *label_7;

    void setupUi(QWidget *StoreWindow)
    {
        if (StoreWindow->objectName().isEmpty())
            StoreWindow->setObjectName("StoreWindow");
        StoreWindow->resize(257, 362);
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
        StoreWindow->setPalette(palette);
        graphicsView = new QGraphicsView(StoreWindow);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(16, 16, 32, 32));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        graphicsView->setPalette(palette1);
        label = new QLabel(StoreWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 20, 131, 41));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush2(QColor(190, 190, 190, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label->setPalette(palette2);
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font.setPointSize(26);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(StoreWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 70, 180, 20));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_2->setPalette(palette3);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(StoreWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 112, 256, 32));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_3->setPalette(palette4);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(StoreWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 160, 256, 32));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_4->setPalette(palette5);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(StoreWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 208, 256, 32));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_5->setPalette(palette6);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(StoreWindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 256, 256, 32));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_6->setPalette(palette7);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);
        graphicsView_2 = new QGraphicsView(StoreWindow);
        graphicsView_2->setObjectName("graphicsView_2");
        graphicsView_2->setGeometry(QRect(32, 112, 192, 32));
        QPalette palette8;
        QBrush brush3(QColor(191, 64, 64, 0));
        brush3.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        graphicsView_2->setPalette(palette8);
        label_7 = new QLabel(StoreWindow);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 290, 201, 51));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_7->setPalette(palette9);
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);

        retranslateUi(StoreWindow);

        QMetaObject::connectSlotsByName(StoreWindow);
    } // setupUi

    void retranslateUi(QWidget *StoreWindow)
    {
        StoreWindow->setWindowTitle(QCoreApplication::translate("StoreWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("StoreWindow", "\345\225\206\345\272\227", nullptr));
        label_2->setText(QCoreApplication::translate("StoreWindow", "\344\273\267\346\240\274\357\274\23215\351\207\221\345\270\201", nullptr));
        label_3->setText(QCoreApplication::translate("StoreWindow", "\346\217\220\345\215\207 800 \347\202\271\347\224\237\345\221\275", nullptr));
        label_4->setText(QCoreApplication::translate("StoreWindow", "\346\217\220\345\215\207 4 \347\202\271\346\224\273\345\207\273\345\212\233", nullptr));
        label_5->setText(QCoreApplication::translate("StoreWindow", "\346\217\220\345\215\207 4 \347\202\271\351\230\262\345\276\241\345\212\233", nullptr));
        label_6->setText(QCoreApplication::translate("StoreWindow", "\347\246\273\345\274\200\345\225\206\345\272\227", nullptr));
        label_7->setText(QCoreApplication::translate("StoreWindow", "\357\274\210\346\214\211\345\233\236\350\275\246\346\210\226\347\251\272\346\240\274\351\224\256\347\241\256\350\256\244\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StoreWindow: public Ui_StoreWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOREWINDOW_H
