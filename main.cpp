#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "options.h"
#include "battlefield.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

