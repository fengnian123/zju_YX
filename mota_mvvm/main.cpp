#include "app/app.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>

int main(int argc, char *argv[])
{
    //std::cout << std::endl;
    QApplication a(argc, argv);
    App* app = new App;
    app->run();
    return a.exec();
}
