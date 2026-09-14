#include <QPainter>
#include "QtWidgetsSimulation.h"



QtWidgetsSimulation::QtWidgetsSimulation(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QtPaintEventGrid(nullptr); // Call the grid painting function
}

QtWidgetsSimulation::~QtWidgetsSimulation()
{}

void QtWidgetsSimulation::QtPaintEventGrid(QPaintEvent * event)
{
	Q_UNUSED(event);

	QPainter painter(this);

	int SizeCase = 50; // Size of the grid squares
	QPen pen(Qt::blue, 1, Qt::SolidLine);

	for (int x = 0; x < width(); x+= SizeCase)
	{
		painter.drawLine(x, 0, x, height());
	}

	for (int y = 0; y < height(); y += SizeCase)
	{
		painter.drawLine(0, y, width(), y);
	}
}

