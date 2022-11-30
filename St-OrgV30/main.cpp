#include "mainwindow.h"
#include <QWidget>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("St.Org");
    w.show();
    return a.exec();
}
