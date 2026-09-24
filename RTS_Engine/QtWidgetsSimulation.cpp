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
	unsigned int SizeAnimal = m_SizeCase/5; // Size of the animal points

	for (int x = 0; x < width(); x+= m_SizeCase)
	{
		painter.drawLine(x, 0, x, height());
		
	}

	for (int y = 0; y < height(); y += m_SizeCase)
	{
		painter.drawLine(0, y, width(), y);
	}

	for (int i = 0; i < width() / m_SizeCase; ++i)
	{
		for (int j = 0; j < height() / m_SizeCase; ++j) 
		{
			//CTile* tile = get_tile(i, j);
			
			/*if (!tile->isTile_empty(*tile))
			{
				paintAnimals(painter, (i * m_SizeCase + m_SizeCase / 2) - SizeAnimal, (j * m_SizeCase + m_SizeCase / 2) - SizeAnimal, SizeAnimal, true);
				paintAnimals(painter, (i * m_SizeCase + m_SizeCase / 2) - SizeAnimal, (j * m_SizeCase + m_SizeCase / 2) + SizeAnimal, SizeAnimal, true);
				paintAnimals(painter, (i * m_SizeCase + m_SizeCase / 2) + SizeAnimal, (j * m_SizeCase + m_SizeCase / 2) - SizeAnimal, SizeAnimal, false);
				paintAnimals(painter, (i * m_SizeCase + m_SizeCase / 2) + SizeAnimal, (j * m_SizeCase + m_SizeCase / 2) + SizeAnimal, SizeAnimal, false);
			}*/
		}
	}
}

void QtWidgetsSimulation::paintAnimals(QPainter& painter, int x, int y, int size, bool is_predator)
{
	if (is_predator)
	{
		painter.setPen(QPen(Qt::red, size, Qt::SolidLine));
	}
	else
	{
		painter.setPen(QPen(Qt::blue, size, Qt::SolidLine));
	}

	painter.drawPoint(x, y);
}

void QtWidgetsSimulation::setGridSize(int newSize)
{
	m_SizeCase = newSize;
	update();
}