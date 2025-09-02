#include <QApplication>
#include <QFile>
#include "MainWindow/mainwindow.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    m.show();
    return QApplication::exec();
}
