#include "mandelbrotwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<JobResult>("JobResult");
    qRegisterMetaType<QList<JobResult>>("QList<JobResult>");
    MandelbrotWidget w;
    w.show();
    return a.exec();
}
