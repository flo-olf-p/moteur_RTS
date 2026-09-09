#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RTS_Engine.h"

class RTS_Engine : public QMainWindow
{
    Q_OBJECT

public:
    RTS_Engine(QWidget *parent = nullptr);
    ~RTS_Engine();

private:
    Ui::RTS_EngineClass ui;
};

