#include "mainwindow.h"
#include <QApplication>
#include <matrix.cpp>
#include "simplexinfo.h"
#include <iostream>
#include <vector>
#include "dialoganswers.h"
#include "dialogcon.h"
#include "dialogwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();





    return a.exec();
}
