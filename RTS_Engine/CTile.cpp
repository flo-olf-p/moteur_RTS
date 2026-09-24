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
			m_animals[i][j] = nullptr;
		}
	}
}

bool CTile::isTile_full(CTile& tile) const
{
	const unsigned int size = std::size(m_animals);

	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++i)
		{
			if (m_animals[i][j] == nullptr)
			{
				return false;
			}
		}
	}

	return true;
}

bool CTile::isTile_empty(CTile& tile) const
{

	const unsigned int size = std::size(m_animals);

	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++i)
		{
			if (m_animals[i][j] != nullptr)
			{
				return false;
			}
		}
	}

	return true;
}
