QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    view/view.cpp \
    app/app.cpp \
    viewmodel/viewmodel.cpp \
    model/model.cpp \
    command/command.cpp \
    notification/notification.cpp \
    variables/variables.cpp

HEADERS += \
    view/view.h \
    app/app.h \
    viewmodel/viewmodel.h \
    model/model.h \
    command/command.h \
    notification/notification.h \
    variables/variables.h

FORMS += \
    view/view.ui

RESOURCES += \
    mtgraphics.qrc

CONFIG += lrelease

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
