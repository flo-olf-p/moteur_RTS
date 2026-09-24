#pragma once
#include "CAnimal.h"
#include <array>

class CTile
{
private:
	std::array<std::array<CAnimal*, 2>, 2> m_animals;

public:
	CTile(std::array<std::array<CAnimal*, 2>, 2> animals);
	~CTile();


	std::array<std::array<CAnimal*, 2>, 2> get_animals() const { return m_animals; }
	CAnimal* get_animal(size_t x, size_t y) const { return m_animals[x][y]; }

	void set_animals(std::array<std::array<CAnimal*, 2>, 2> animals) { m_animals = animals; }
	void set_animal(CAnimal* animal, size_t x, size_t y) { m_animals[x][y] = animal; }
	bool isTile_full(CTile& tile) const;
	bool isTile_empty(CTile& tile) const;
};