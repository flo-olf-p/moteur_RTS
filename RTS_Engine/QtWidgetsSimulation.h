#pragma once

#include <QWidget>
#include "ui_QtWidgetsSimulation.h"
#include "CTile.h"
#include <vector>
#include <QPainter>
#include "CWolf.h"
#include "CRabbit.h"

class QtWidgetsSimulation : public QWidget
{
	Q_OBJECT

public:
	QtWidgetsSimulation(QWidget *parent = nullptr);
	~QtWidgetsSimulation();

	CTile* get_tile(size_t x, size_t y) const { return m_board[x][y]; }
	void set_tile(CTile& tile, size_t x, size_t y) { m_board[x][y] = &tile; }

	void addAnimalToBoard(CAnimal* animal, int boardX, int boardY, int tileX, int tileY);
	void reinitializeBoard();

private:
	Ui::QtWidgetsSimulationClass ui;
	unsigned int m_SizeCase = 50;
	std::vector<std::vector<CTile*>> m_board;

	void initializeBoard();

protected:
	void paintEvent(QPaintEvent* event) override;

	void paintAnimalRect(QPainter& painter, int x, int y, int width, int height, bool is_carnivorous);


public slots:
    void setGridSize(int newSize);
	void addAnimalButton(int PredNumber, int HerbNumber);
};

