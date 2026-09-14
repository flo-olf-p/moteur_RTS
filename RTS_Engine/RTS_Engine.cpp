#include "RTS_Engine.h"

#include "QtWidgetsDebugMenu.h"
#include "QtWidgetsSimulation.h"

#include <QHBoxLayout>
#include <QWidget>

RTS_Engine::RTS_Engine(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

}

RTS_Engine::~RTS_Engine()
{}

