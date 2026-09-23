#pragma once

#include <QWidget>
#include "ui_QtWidgetsSimulation.h"
#include "CTile.h"
#include <vector>

class QtWidgetsSimulation : public QWidget
{
	Q_OBJECT

public:
	QtWidgetsSimulation(QWidget *parent = nullptr);
	~QtWidgetsSimulation();

private:
	Ui::QtWidgetsSimulationClass ui;
	unsigned int m_SizeCase = 50;
	std::vector<std::vector<CTile*>> m_board;

protected:
	void paintEvent(QPaintEvent* event) override;
	void paintAnimals(QPainter& painter, int x, int y, int size, bool pred);

public slots:
    void setGridSize(int newSize);
};

