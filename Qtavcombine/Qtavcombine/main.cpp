#include "pch.h"

#include "Qtavcombine.h"
#include <QtWidgets/QApplication>
#include <qtextcodec.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qtavcombine w;
    w.show();
    return a.exec();
}
