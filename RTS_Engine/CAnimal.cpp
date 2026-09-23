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
		    if ()
	}*/
	
	return true;
}

void CAnimal::move(std::vector<std::vector<CCase>> grid)
{
    //0:haut, 1:droite, 2:bas, 3:gauche, dans le sens des aiguille d'une montre en commençant à midi en gros
    int random = 0;
    for (int i = 0; i < std::size(grid); i++)
        for (int j = 0; j < std::size(grid[i]); j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    if (grid[i][j].get_array(k,l).get_animal() == this)
                        if (random == 0)
                            if (j == 0)
                                
                        else if (random == 1)
                            if (i == std::size(grid)-1)
                                
                        else if (random == 2)
                            if (j == std::size(grid[i])-1)
                                
                        else if (random == 3)
                            else if (i == 0)
                                
                        else
                            std::cerr << "le random n'a pas fonctionner";
}
