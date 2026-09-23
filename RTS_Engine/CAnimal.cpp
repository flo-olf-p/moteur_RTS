#include "CAnimal.h"


CAnimal::CAnimal(float speed, float reproduction_rate, float mortality_rate, float age, float life_expectancy, float gender, float time_before_reproduction, float hunger, std::pair<int, int> location)
{
	m_age = age;
	m_gender = gender;
	m_hunger = hunger;
	m_life_expectancy = life_expectancy;
	m_speed = speed;
	m_reproduction_rate = reproduction_rate;
	m_mortality_rate = mortality_rate;
	m_time_before_reproduction = time_before_reproduction;
	m_location = location;
}

class CAnimal
{
	bool IsAlive(tab){
		if(m_age > m_life_expectancy)
			return false;
		if(m_hunger == 0)
			return false;
		for(size_t i=0;i<std::size(tab);i++){
		    if (tab[i].m_location.first == m_location.first && tab[i].m_location.second == m_location.second && tab[i].)
		}
		return true;
	}
}
