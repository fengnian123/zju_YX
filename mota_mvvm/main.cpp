#include "view/view.h"
#include "app/app.h"
#include "viewmodel/viewmodel.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    App* app = new App;
    app->run();
    return a.exec();
}
