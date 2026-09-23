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
			/*paintAnimals(painter, (i * m_SizeCase + m_SizeCase / 2), (j * m_SizeCase + m_SizeCase / 2), SizeAnimal, true);*/

			/*paintAnimals(painter, (i * m_SizeCase + m_SizeCase / 2) - SizeAnimal, (j * m_SizeCase + m_SizeCase / 2), SizeAnimal, true);
			paintAnimals(painter, (i * m_SizeCase + m_SizeCase / 2) +SizeAnimal, (j * m_SizeCase + m_SizeCase / 2), SizeAnimal, false);*/

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

void QtWidgetsSimulation::set_param_animals(std::string name, float speed, float reproduction_rate, float mortality_rate, float life_expectancy, float time_before_reproduction, float time_before_hunger){
	std::get<0>(m_param_animals[std::size(m_param_animals)]) = name;
	std::get<1>(m_param_animals[std::size(m_param_animals)]) = speed;
	std::get<2>(m_param_animals[std::size(m_param_animals)]) = reproduction_rate;
	std::get<3>(m_param_animals[std::size(m_param_animals)]) = mortality_rate;
	std::get<4>(m_param_animals[std::size(m_param_animals)]) = life_expectancy;
	std::get<5>(m_param_animals[std::size(m_param_animals)]) = time_before_reproduction;
	std::get<6>(m_param_animals[std::size(m_param_animals)]) = time_before_hunger;
}