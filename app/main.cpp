#include "traffic_signmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Traffic_signMainWindow w;
    w.show();
    return a.exec();
}
