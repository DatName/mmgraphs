#include "mainwindow.h"
#include <QApplication>
#include <ev.h>
#include "datareceiver.h"
#include "datacollector.h"
#include "qcustomplot.h"
#include <QObject>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return  a.exec();
}
