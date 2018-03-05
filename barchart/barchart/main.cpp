#include "barchart.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    barchart w;
    w.show();
    return a.exec();
}
