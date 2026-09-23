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
	std::vector<std::tuple<std::string, float, float, float, float, float, float>> get_param_animals();
	void set_param_animals(std::vector<(std::string name, float speed, float reproduction_rate, float mortality_rate, float life_expectancy, float time_before_reproduction, float time_before_hunger);
    

private:
	Ui::QtWidgetsSimulationClass ui;
	int m_SizeCase = 50; // Size of the grid squares
	
	//0:id, 1:speed, 2:reproduction_rate, 3:mortality_rate, 4:life_expectancy, 5:time_before_reproduction, 6:time_before_hunger)
	std::vector<std::tuple<std::string, float, float, float, float, float, float>> m_param_animals;
protected:
	void paintEvent(QPaintEvent* event) override;
	void paintAnimals(QPainter& painter, int x, int y, int size, bool pred);

public slots:
    void setGridSize(int newSize);
};

