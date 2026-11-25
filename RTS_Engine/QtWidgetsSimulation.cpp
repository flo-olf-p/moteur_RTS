#include "QtWidgetsSimulation.h"

QtWidgetsSimulation::QtWidgetsSimulation(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initializeBoard();
	
}

QtWidgetsSimulation::~QtWidgetsSimulation()
{
	for (auto& row : m_board)
	{
		for (auto tile : row)
		{
			delete tile;
		}
	}
	m_board.clear();
}

void QtWidgetsSimulation::initializeBoard()
{
	int gridWidth = width() / m_SizeCase;
	int gridHeight = height() / m_SizeCase;

	m_board.resize(gridWidth);
	for (int x = 0; x < gridWidth; ++x)
	{
		m_board[x].resize(gridHeight);
		for (int y = 0; y < gridHeight; ++y)
		{
			std::array<std::array<CAnimal*, 2>, 2> emptyAnimals = { {{nullptr, nullptr}, {nullptr, nullptr}} };
			m_board[x][y] = new CTile(emptyAnimals);
		}
	}
}

void QtWidgetsSimulation::addAnimalToBoard(CAnimal* animal, int boardX, int boardY, int tileX, int tileY)
{
	if (boardX >= 0 && boardX < (int)m_board.size() &&
		boardY >= 0 && boardY < (int)m_board[0].size() &&
		tileX >= 0 && tileX < 2 &&
		tileY >= 0 && tileY < 2)
	{
		m_board[boardX][boardY]->set_animal(animal, tileX, tileY);
	}
}

void QtWidgetsSimulation::reinitializeBoard()
{
	for (auto& row : m_board)
	{
		for (auto tile : row)
		{
			delete tile;
		}
	}
	m_board.clear();

	int gridWidth = width() / m_SizeCase;
	int gridHeight = height() / m_SizeCase;

	m_board.resize(gridWidth);
	for (int x = 0; x < gridWidth; ++x)
	{
		m_board[x].resize(gridHeight);
		for (int y = 0; y < gridHeight; ++y)
		{
			std::array<std::array<CAnimal*, 2>, 2> emptyAnimals = { {{nullptr, nullptr}, {nullptr, nullptr}} };
			m_board[x][y] = new CTile(emptyAnimals);
		}
	}
}

void QtWidgetsSimulation::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);

	QPainter painter(this);
	painter.setPen(QPen(Qt::gray, 1, Qt::SolidLine));
	unsigned int SizeAnimal = m_SizeCase / 5; // Taille des rectangles animaux

	// Dessiner la grille
	for (int x = 0; x < width(); x += m_SizeCase)
	{
		painter.drawLine(x, 0, x, height());
	}

	for (int y = 0; y < height(); y += m_SizeCase)
	{
		painter.drawLine(0, y, width(), y);
	}

	for (int i = 0; i < (int)m_board.size(); ++i)
	{
		for (int j = 0; j < (int)m_board[i].size(); ++j)
		{
			CTile* tile = m_board[i][j];

			// Vérifier les 4 positions possibles 
			// haut gauche
			CAnimal* animal = tile->get_animal(0, 0);
			if (animal != nullptr)
			{
				paintAnimalRect(painter,
					i * m_SizeCase + m_SizeCase / 4,
					j * m_SizeCase + m_SizeCase / 4,
					SizeAnimal, SizeAnimal,
					animal->get_is_carnivorous());
			}

			// haut droite
			animal = tile->get_animal(1, 0);
			if (animal != nullptr)
			{
				paintAnimalRect(painter,
					i * m_SizeCase + m_SizeCase / 2,
					j * m_SizeCase + m_SizeCase / 4,
					SizeAnimal, SizeAnimal,
					animal->get_is_carnivorous());
			}

			// bas gauche
			animal = tile->get_animal(0, 1);
			if (animal != nullptr)
			{
				paintAnimalRect(painter,
					i * m_SizeCase + m_SizeCase / 4,
					j * m_SizeCase + m_SizeCase / 2,
					SizeAnimal, SizeAnimal,
					animal->get_is_carnivorous());
			}

			// bas droite
			animal = tile->get_animal(1, 1);
			if (animal != nullptr)
			{
				paintAnimalRect(painter,
					i * m_SizeCase + m_SizeCase / 2,
					j * m_SizeCase + m_SizeCase / 2,
					SizeAnimal, SizeAnimal,
					animal->get_is_carnivorous());
			}
		}
	}
}

void QtWidgetsSimulation::paintAnimalRect(QPainter& painter, int x, int y, int width, int height, bool is_carnivorous)
{
	if (is_carnivorous)
	{
		painter.fillRect(x, y, width, height, QColor(Qt::red));
		painter.setPen(QPen(Qt::darkRed, 1, Qt::SolidLine));
	}
	else
	{
		painter.fillRect(x, y, width, height, QColor(Qt::blue));
		painter.setPen(QPen(Qt::darkBlue, 1, Qt::SolidLine));
	}
	painter.drawRect(x, y, width, height);
}

void QtWidgetsSimulation::addAnimalButton(int PredNumber, int HerbNumber)
{
	for (int i = 0; i < HerbNumber; ++i)
	{
		CRabbit* rabbit = new CRabbit(2, 0.5f, 0.1f, 30, 5, 10, false);
		addAnimalToBoard(rabbit, rand() % m_board.size(), rand() % m_board[0].size(), rand() % 2, rand() % 2);
	}
	for (int i = 0; i < PredNumber; ++i)
	{
		CWolf* wolf = new CWolf(3, 0.3f, 0.15f, 40, 7, 8, true);
		addAnimalToBoard(wolf, rand() % m_board.size(), rand() % m_board[0].size(), rand() % 2, rand() % 2);
	}

	update();
}

void QtWidgetsSimulation::setGridSize(int newSize)
{
	m_SizeCase = newSize;
	update();
	reinitializeBoard();
}