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
	int SizeAnimal = m_SizeCase/5; // Size of the animal points

	for (int x = 0; x < width(); x+= m_SizeCase)
	{
		painter.drawLine(x, 0, x, height());
		
	}

	for (int y = 0; y < height(); y += m_SizeCase)
	{
		painter.drawLine(0, y, width(), y);
	}

	for (int i = 0; i < width() / m_SizeCase; i++)
	{
		for (int j = 0; j < height() / m_SizeCase; j++) {
			paintAnimals(painter, (i * m_SizeCase + m_SizeCase / 2) - SizeAnimal, (j * m_SizeCase + m_SizeCase / 2) - SizeAnimal, SizeAnimal, true);
			paintAnimals(painter, (i * m_SizeCase + m_SizeCase / 2) - SizeAnimal, (j * m_SizeCase + m_SizeCase / 2) + SizeAnimal, SizeAnimal, true);
			paintAnimals(painter, (i * m_SizeCase + m_SizeCase / 2) + SizeAnimal, (j * m_SizeCase + m_SizeCase / 2) - SizeAnimal, SizeAnimal, false);
			paintAnimals(painter, (i * m_SizeCase + m_SizeCase / 2) + SizeAnimal, (j * m_SizeCase + m_SizeCase / 2) + SizeAnimal, SizeAnimal, false);
		}
	}
}

void QtWidgetsSimulation::paintAnimals(QPainter& painter, int x, int y, int size, bool pred)
{
	if (pred)
	{
		painter.setPen(QPen(Qt::red, 10, Qt::SolidLine));
	}
	else
	{
	painter.setPen(QPen(Qt::blue, 10, Qt::SolidLine));
	}
	painter.drawPoint(x, y);
}

void QtWidgetsSimulation::setGridSize(int newSize)
{
	m_SizeCase = newSize;
	update();
}