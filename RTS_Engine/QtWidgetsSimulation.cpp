#include "QtWidgetsSimulation.h"
#include <iostream>
#include "QtWidgetsDebugMenu.h"

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
			std::array<std::array<CAnimal*, 2>, 2> animals = { {{nullptr,nullptr},{nullptr,nullptr}} };
			m_board[x][y] = new CTile(animals);
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
			std::array<std::array<CAnimal*, 2>, 2> animals = { {{nullptr,nullptr},{nullptr,nullptr}} };
			m_board[x][y] = new CTile(animals);
		}
	}
}

void QtWidgetsSimulation::updateTile(CTile* tile, std::array<CTile*, 4> neighbors, std::unordered_set<CAnimal*>& moved)
{
	
	for (size_t i = 0; i < 2; ++i)
	{
		for (size_t j = 0; j < 2; ++j)
		{
			CAnimal* animal = tile->get_animal(i, j);
			if (animal == nullptr || moved.count(animal)) continue;
			if (!animal->isAlive())
			{
				if (animal->get_is_carnivorous()) { m_predNb -= 1; }
				else { m_herbNb -= 1; }
				tile->delete_animal(i, j);
				continue;
			}
			animal->set_age(animal->get_age() + 1);



			std::vector<CTile*> candidates;
			for (CTile* ele : neighbors)
				if (ele != tile && !ele->is_tile_full())
					candidates.push_back(ele);
			if (candidates.empty()) continue;

			CTile* destination = candidates[std::rand() % candidates.size()];
			auto freePlaces = destination->checkPlaces();           
			auto randomFreePlace = freePlaces[std::rand() % freePlaces.size()];

			destination->set_animal(animal, randomFreePlace.first, randomFreePlace.second);
			tile->set_animal(nullptr, i, j);
			moved.insert(animal);
		}
	}
	
}

void QtWidgetsSimulation::timeForReproduction()
{
	for (size_t i = 0; i < m_board.size(); i++)
	{
		for (CTile* tile : m_board[i])
		{
			if (!tile->can_herb_reproduce()) continue;

			auto freePlaces = tile->checkPlaces();
			auto randomFreePlace = freePlaces[std::rand() % freePlaces.size()];
			tile->set_animal(new CRabbit(2, 0.5f, 0.1f, 30, 5, 10, false), randomFreePlace.first, randomFreePlace.second);
			m_herbNb += 1;
		}
	}
}

void QtWidgetsSimulation::updateSimulation()
{
	size_t sizeAxeX = m_board.size();
	std::unordered_set<CAnimal*> moved;
	for (size_t i = 0; i < sizeAxeX; i++)
	{
		size_t sizeAxeY = m_board[i].size();
		for (size_t j = 0; j < sizeAxeY; j++)
		{
			CTile* currentTile = m_board[i][j];
			if (!currentTile->is_tile_empty())
			{
				std::array<CTile*, 4> neighbors = { m_board[(i + sizeAxeX - 1) % sizeAxeX][j] ,m_board[(i + 1) % sizeAxeX][j] ,m_board[i][(j + sizeAxeY - 1) % sizeAxeY] ,m_board[i][(j + 1) % sizeAxeY] };
				updateTile(currentTile, neighbors, moved);
			}
		}
	}
	qDebug() << "fin de l'update";
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
	if (m_board.empty() || m_board[0].empty()) return;
	for (int i = 0; i < HerbNumber; ++i)
	{
		CRabbit* rabbit = new CRabbit(2, 0.5f, 0.1f, 40, 5, 10, false);
		addAnimalToBoard(rabbit, rand() % m_board.size(), rand() % m_board[0].size(), rand() % 2, rand() % 2);
		m_herbNb += 1;
	}
	for (int i = 0; i < PredNumber; ++i)
	{
		CWolf* wolf = new CWolf(3, 0.3f, 0.15f, 40, 7, 8, true);
		addAnimalToBoard(wolf, rand() % m_board.size(), rand() % m_board[0].size(), rand() % 2, rand() % 2);
		m_predNb += 1;
	}

	update();
}

void QtWidgetsSimulation::endTurn()
{
	std::cout << "boutton appuyé endturn";
	updateSimulation();
	timeForReproduction();
	emit updateStats(m_predNb, m_herbNb);
	update();
}

void QtWidgetsSimulation::setGridSize(int newSize)
{
	if (newSize < 5) return;
	m_SizeCase = newSize;
	update();
	reinitializeBoard();
}