#include "mainwindow.h"
#include <QApplication>
/**
 * @mainpage GUI Programmierung mit Qt
 * @author Can Oezmaden
 * @date Juli 2017
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
