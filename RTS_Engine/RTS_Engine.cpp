#include "RTS_Engine.h"

#include "QtWidgetsDebugMenu.h"
#include "QtWidgetsSimulation.h"

#include <QHBoxLayout>
#include <QWidget>

RTS_Engine::RTS_Engine(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	connect(ui.widget_2, &QtWidgetsDebugMenu::gridSizeChanged, ui.widget, &QtWidgetsSimulation::setGridSize);
}

RTS_Engine::~RTS_Engine()
{}

