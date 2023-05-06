#include "R6Tools.h"
#include <QtWidgets/QApplication>
#include <QFile>
#include <QIcon>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    R6Tools w;

    QIcon appIcon("Icon.png");
    a.setWindowIcon(appIcon);
    w.setWindowIcon(appIcon);

    w.show();
    return a.exec();
}
