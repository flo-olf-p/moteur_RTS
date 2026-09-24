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

	CTile* get_tile(size_t x, size_t y) const { return m_board[x][y]; }
	void set_tile(CTile& tile, size_t x, size_t y) { m_board[x][y] = &tile; }

private:
	Ui::QtWidgetsSimulationClass ui;
	unsigned int m_SizeCase = 50;
	std::vector<std::vector<CTile*>> m_board;

protected:
	void paintEvent(QPaintEvent* event) override;
	void paintAnimals(QPainter& painter, int x, int y, int size, bool is_predator);

public slots:
    void setGridSize(int newSize);
};

