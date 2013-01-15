#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget window(0);
    window.showMaximized();
    return app.exec();
}
