#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RTS_Engine.h"

class QtWidgetsDebugMenu;
class QtWidgetsSimulation;

class RTS_Engine : public QMainWindow
{
    Q_OBJECT

public:
    RTS_Engine(QWidget *parent = nullptr);
    ~RTS_Engine();

private:
    Ui::RTS_EngineClass ui;

    QtWidgetsDebugMenu* m_WidgetDebugMenu;
    QtWidgetsSimulation* m_WidgetSimulation;
};

