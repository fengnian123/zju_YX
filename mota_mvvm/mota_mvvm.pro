QT       += core gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = MtGui
TEMPLATE = app

SOURCES += \
    main.cpp \
    view/StoreWindow.cpp \
    view/view.cpp \
    app/app.cpp \
    viewmodel/fight_command.cpp \
    viewmodel/floor_change_command.cpp \
    viewmodel/move_down_command.cpp \
    viewmodel/move_left_command.cpp \
    viewmodel/move_right_command.cpp \
    viewmodel/move_up_command.cpp \
    viewmodel/pick_item_command.cpp \
    viewmodel/pick_key_command.cpp \
    viewmodel/buy_atk_command.cpp \
    viewmodel/buy_def_command.cpp \
    viewmodel/buy_hp_command.cpp \
    viewmodel/viewmodel.cpp \
    model/model.cpp \
    command/command.cpp \
    notification/notification.cpp \
    common/variables.cpp \

HEADERS += \
    view/StoreWindow.h \
    view/view.h \
    app/app.h \
    viewmodel/fight_command.h \
    viewmodel/floor_change_command.h \
    viewmodel/move_down_command.h \
    viewmodel/move_left_command.h \
    viewmodel/move_right_command.h \
    viewmodel/move_up_command.h \
    viewmodel/pick_item_command.h \
    viewmodel/pick_key_command.h \
    viewmodel/buy_atk_command.h \
    viewmodel/buy_def_command.h \
    viewmodel/buy_hp_command.h \
    viewmodel/viewmodel.h \
    model/model.h \
    command/command.h \
    notification/notification.h \
    common/variables.h \

FORMS += \
    view/storewindow.ui \
    view/view.ui

RESOURCES += \
    mtgraphics.qrc

CONFIG += lrelease

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
