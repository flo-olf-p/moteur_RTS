#include "CTile.h"

CTile::CTile(std::array<std::array<CAnimal*, 2>, 2> animals)
{
	m_animals = animals;
}

CTile::~CTile()
{
	// Désallocation de la mémoire
	size_t size = std::size(m_animals);
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			delete m_animals[i][j];
			m_animals[i][j] = nullptr;
		}
	}
}

bool CTile::is_tile_full() const
{
	const unsigned int size = std::size(m_animals);

	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			if (m_animals[i][j] == nullptr)
			{
				return false;
			}
		}
	}

	return true;
}

bool CTile::is_tile_empty() const
{

	const unsigned int size = std::size(m_animals);

	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			if (m_animals[i][j] != nullptr)
			{
				return false;
			}
		}
	}

	return true;
}


std::pair<size_t, size_t> CTile::checkWolf() const
{
	return std::pair<size_t, size_t>(4, 4);
}

std::vector<std::pair<unsigned int, unsigned int>> CTile::checkPlaces() const
{
	std::vector<std::pair<unsigned int, unsigned int>> freePlaces;
	for (unsigned int i = 0; i < m_animals.size(); i++)
	{
		for (unsigned int j = 0; j < m_animals.size(); j++)
		{
			if (m_animals[i][j] == nullptr)
			{
				freePlaces.push_back(std::pair<unsigned int, unsigned int>(i, j));
			}
		}
	}


	return freePlaces;
}