#include "FPL.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FPL w;
    w.show();
    return a.exec();
}
