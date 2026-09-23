#include "CAnimal.h"

CAnimal::CAnimal(unsigned int speed, float reproduction_rate, float mortality_rate,
	unsigned int life_expectancy, unsigned int reproduction_delay, unsigned int hunger_delay)
{
	//m_gender = gender;
	m_life_expectancy = life_expectancy;
	m_speed = speed;
	m_reproduction_rate = reproduction_rate;
	m_mortality_rate = mortality_rate;
	m_reproduction_delay = reproduction_delay;
	m_hunger_delay = hunger_delay;
	//m_location = location;
}

bool CAnimal::isAlive() const
{
	if (m_age >= m_life_expectancy || m_hunger == 0)
	{
		return false;
	}
		
	/*for (size_t i = 0; i < std::size(tab); i++)
	{
		    if (tab[i].m_location.first == m_location.first && tab[i].m_location.second == m_location.second && tab[i].)
	}*/
	
	return true;
}
