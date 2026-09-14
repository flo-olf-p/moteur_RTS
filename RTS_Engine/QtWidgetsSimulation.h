#pragma once

#include <QWidget>
#include "ui_QtWidgetsSimulation.h"



class QtWidgetsSimulation : public QWidget
{
	Q_OBJECT

public:
	QtWidgetsSimulation(QWidget *parent = nullptr);
	~QtWidgetsSimulation();

private:
	Ui::QtWidgetsSimulationClass ui;
protected:
	void paintEvent(QPaintEvent* event) override;
	void paintAnimals(QPainter& painter, int x, int y, int size);
};

