#include "noote.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Noote w;
    w.show();
    return a.exec();
}
