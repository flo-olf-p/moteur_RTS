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

void CTile::delete_animal(size_t x, size_t y)
{
	delete m_animals[x][y];
	m_animals[x][y] = nullptr;
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

bool CTile::can_herb_reproduce() const
{
	unsigned int herb = 0;
	for (auto eles : m_animals)
	{
		for (auto ele : eles)
		{
			if (ele == nullptr) continue;
			if (ele->get_age() < 20) continue;
			if (ele->get_reproduction_time() != 0) 
			{
				ele->add_reproduction_time(-1);
				continue;
			}
			if (ele->get_is_carnivorous()) return false;
			++herb;
			ele->set_reproduction_time(ele->get_reproduction_delay());
		}
	}
	return herb >= 2 && !is_tile_full();
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