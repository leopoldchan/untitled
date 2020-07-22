#include "widget.h"

#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget *w=new Widget();
    w->show();
    w->move((QApplication::desktop()->width() - w->width())/2,(QApplication::desktop()->height() - w->height())/2);
    return a.exec();
}
