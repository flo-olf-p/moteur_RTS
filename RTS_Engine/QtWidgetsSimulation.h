#pragma once

#include <QWidget>
#include "ui_QtWidgetsSimulation.h"
#include <vector>
#include <tuple>
#include <string>

class QtWidgetsSimulation : public QWidget
{
	Q_OBJECT

public:
	QtWidgetsSimulation(QWidget *parent = nullptr);
	~QtWidgetsSimulation();

private:
	Ui::QtWidgetsSimulationClass ui;
	int m_SizeCase = 50; // Size of the grid squares

protected:
	void paintEvent(QPaintEvent* event) override;
	void paintAnimals(QPainter& painter, int x, int y, int size, bool pred);

public slots:
    void setGridSize(int newSize);
};

