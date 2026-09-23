#include "RTS_Engine.h"
#include "CRabbit.h"
#include <qDebug>

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    RTS_Engine window;
    window.show();

    CRabbit test = CRabbit(1, 0.5, 0.8, 25, 10, 3);
    qDebug() << "Je suis un lapin avec une vitesse de" << test.get_speed() << "une faim de " << test.get_hunger() << "et une espérence de vie de " << test.get_life_expectancy();

    return app.exec();
}
