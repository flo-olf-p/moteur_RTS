#pragma once

#include <QWidget>
#include "ui_QtWidgetsDebugMenu.h"

class QtWidgetsDebugMenu : public QWidget
{
	Q_OBJECT

public:
	QtWidgetsDebugMenu(QWidget* parent = nullptr);
	~QtWidgetsDebugMenu();

private:
	Ui::QtWidgetsDebugMenuClass ui;

signals:
	void gridSizeChanged(int newSize);
};

