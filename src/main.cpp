#include "R6Tools.h"
#include <QtWidgets/QApplication>
#include <QFile>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    R6Tools w;
    w.show();
    return a.exec();
}
