#include "GEN.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GEN w;
    w.show();
    return a.exec();
}
