#include "RTS_Engine.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    RTS_Engine window;
    window.show();


    return app.exec();
}
