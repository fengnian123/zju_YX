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
    view/view.cpp \
    app/app.cpp \
    viewmodel/viewmodel.cpp \
    model/model.cpp \
    command/command.cpp \
    notification/notification.cpp \
    variables/variables.cpp \
    command/fight_command.cpp \
    command/pick_key_command.cpp \
    command/door_open_command.cpp \
    command/floor_change_command.cpp \
    command/dialog_command.cpp \
    command/move_up_command.cpp \
    command/move_down_command.cpp \
    command/move_left_command.cpp \
    command/move_right_command.cpp \
    command/pick_item_command.cpp

HEADERS += \
    total.h \
    view/view.h \
    app/app.h \
    viewmodel/viewmodel.h \
    model/model.h \
    command/command.h \
    notification/notification.h \
    variables/variables.h \
    command/fight_command.h \
    command/pick_key_command.h \
    command/door_open_command.h \
    command/floor_change_command.h \
    command/dialog_command.h \
    command/move_up_command.h \
    command/move_down_command.h \
    command/move_left_command.h \
    command/move_right_command.h \
    command/pick_item_command.h

FORMS += \
    view/view.ui

RESOURCES += \
    mtgraphics.qrc

CONFIG += lrelease

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
