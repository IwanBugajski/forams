#include "foramsmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ForamsMainWindow w;
    w.show();

    return a.exec();
}
