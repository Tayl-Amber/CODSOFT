#include "todolist.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CTodolist app;
    app.show();

    return a.exec();
}
