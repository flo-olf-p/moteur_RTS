#include <QPainter>
#include "QtWidgetsSimulation.h"



QtWidgetsSimulation::QtWidgetsSimulation(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

QtWidgetsSimulation::~QtWidgetsSimulation()
{}

void QtWidgetsSimulation::paintEvent(QPaintEvent * event)
{

	Q_UNUSED(event);

	QPainter painter(this);
	painter.setPen(QPen(Qt::gray, 1, Qt::SolidLine));
	int SizeCase = 50; // Size of the grid squares
	int SizeAnimal = 10; // Size of the animal points

	for (int x = 0; x < width(); x+= SizeCase)
	{
		painter.drawLine(x, 0, x, height());
		
	}

	for (int y = 0; y < height(); y += SizeCase)
	{
		painter.drawLine(0, y, width(), y);
	}

	for (int i = 0; i < width() / SizeCase; i++)
	{
		for (int j = 0; j < height() / SizeCase; j++) {
			paintAnimals(painter, (i * SizeCase + SizeCase / 2) - SizeAnimal, (j * SizeCase + SizeCase / 2) - SizeAnimal, SizeAnimal);
			paintAnimals(painter, (i * SizeCase + SizeCase / 2) - SizeAnimal, (j * SizeCase + SizeCase / 2) + SizeAnimal, SizeAnimal);
			paintAnimals(painter, (i * SizeCase + SizeCase / 2) + SizeAnimal, (j * SizeCase + SizeCase / 2) - SizeAnimal, SizeAnimal);
			paintAnimals(painter, (i * SizeCase + SizeCase / 2) + SizeAnimal, (j * SizeCase + SizeCase / 2) + SizeAnimal, SizeAnimal);
		}
	}
}

void QtWidgetsSimulation::paintAnimals(QPainter& painter, int x, int y, int size)
{
	painter.setPen(QPen(Qt::blue, 10, Qt::SolidLine));
	painter.drawPoint(x, y);
}

