#include "CAnimal.h"

#include <iostream>
#include <vector>

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

bool CAnimal::isAlive(std::vector<std::vector<CCase>> grid, unsigned int x, unsigned int y) const
{
	if (m_age >= m_life_expectancy || m_hunger == 0)
	{
		return false;
	}
	std::pair<unsigned int, unsigned int> isWolf = grid[x][y].checkWolf();
	if (isWolf.first != 4 && isWolf.second != 4)
	{
		int rand = rand()%2 +1;
		if (rand == 2)
		{
			return false;
		}
		//Plus tard dans les étapes :
		if (grid[x][y].get_array(isWolf.first, isWolf.second).get_animal()->m_hunger <= grid[x][y].get_array(isWolf.first, isWolf.second).get_animal()->m_hunger_delay)
		{
			grid[x][y].get_array(isWolf.first, isWolf.second).get_animal()->m_hunger += 4;
		 	return false;
		}
	}
	
	int rand = rand()%(this->get_mortality_rate()/10) +1;
	if (rand == 1)
	{
		return false;
	}
	
	return true;
}

void CAnimal::humdrum(std::vector<std::vector<CCase>> grid)
{
	//x: de gauche à droite
    for (int x = 0; x < std::size(grid); x++)
    {
	    //y: de haut en bas
    	for (int y = 0; y < std::size(grid[x]); y++)
    	{
    		//zx: array de droite à gauche
    		for (int zx = 0; zx < 2; zx++)
    		{
    			//zy: array de haut en bas
    			for (int zy = 0; zy < 2; zy++)
    			{
    				if(grid[x][y].get_array(zx,zy).get_animal() != nullptr)
    				{
    					if(grid[x][y].get_array(zx,zy).get_animal().isAlive(grid,x,y)==true)
    					{
    						grid[x][y].get_array(zx,zy).get_animal().move(grid,x,y,zx,zy);
    					}
    					else
    					{
    						grid[x][y].get_array(zx,zy).kill();
    					}
    				}
    			}
    		}
    	}
    }
}

std::pair<unsigned int, unsigned int> CAnimal::checkPlaces() const
{
	return std::pair<unsigned int, unsigned int>(4, 4);
}

std::pair<unsigned int, unsigned int> CAnimal::checkWolf() const
{
	return std::pair<unsigned int, unsigned int>(4, 4);
}

void CAnimal::move(std::vector<std::vector<CCase>> grid, unsigned int x, unsigned int y, unsigned int zx, unsigned int zy)
{
	//0:haut, 1:droite, 2:bas, 3:gauche, dans le sens des aiguille d'une montre en commençant à midi en gros, et 4 c'est la boucle qui s'arrête
	
	int rand = rand()%3 +0;
	int const random = rand;
	std::pair<unsigned int, unsigned int> isPlace;
	while (rand == 4)
	{
		//haut
		if (rand == 0)
		{
			//bordure haut
			if (y == 0)
			{
				isPlace = grid[x][std::size(grid[x])-1].checkPlaces();
				if (isPlace.first == 4 && isPlace.second == 4)
				{
					if (random == 1)
					{
						rand = 4;
					}
					else
					{
						rand = 1;
					}
				}
				else
				{
					grid[x][std::size(grid[x])-1].set_array(grid[x][y].get_array(zx, zy).get_animal, isPlace.first, isPlace.second);
					grid[x][y].set_array(nullptr, zx, zy);
					this->m_age++;
					rand = 4;
				}
			}
			else
			{
				isPlace = grid[x][y-1].checkPlaces();
				if (isPlace.first == 4 && isPlace.second == 4)
				{
					if (random == 1)
					{
						rand = 4;
					}
					else
					{
						rand = 1;
					}
				}
				else
				{
					grid[x][y-1].set_array(grid[x][y].get_array(zx, zy).get_animal, isPlace.first, isPlace.second);
					grid[x][y].set_array(nullptr, zx, zy);
					this->m_age++;
					rand = 4;
				}
			}
		}
		//droite
		else if (rand == 1)
		{
			//bordure droite
			if (x == std::size(grid)-1)
			{
				isPlace = grid[0][y].checkPlaces();
				if (isPlace.first == 4 && isPlace.second == 4)
				{
					if (random == 2)
						rand = 4;
					else
					{
						rand = 2;
					}
				}
				else
				{
					grid[0][y].set_array(grid[x][y].get_array(zx, zy).get_animal, isPlace.first, isPlace.second);
					grid[x][y].set_array(nullptr, zx, zy);
					this->m_age++;
					rand = 4;
				}
			}
			else
			{
				isPlace = grid[x][y-1].checkPlaces();
				if (isPlace.first == 4 && isPlace.second == 4)
				{
					if (random == 2)
						rand = 4;
					else
					{
						rand = 2;
					}
				}
				else
				{
					grid[x][y-1].set_array(grid[x][y].get_array(zx, zy).get_animal, isPlace.first, isPlace.second);
					grid[x][y].set_array(nullptr, zx, zy);
					this->m_age++;
					rand = 4;
				}
			}
		}
		//bas
		else if (rand == 2)
		{
			//bordure bas
			if (y == std::size(grid[x])-1)
			{
				isPlace = grid[x][0].checkPlaces();
				if (isPlace.first == 4 && isPlace.second == 4)
				{
					if (random == 3)
						rand = 4;
					else
					{
						rand = 3;
					}
				}
				else
				{
					grid[x][0].set_array(grid[x][y].get_array(zx, zy).get_animal, isPlace.first, isPlace.second);
					grid[x][y].set_array(nullptr, zx, zy);
					this->m_age++;
					rand = 4;
				}
			}
			else
			{
				isPlace = grid[x][y+1].checkPlaces();
				if (isPlace.first == 4 && isPlace.second == 4)
				{
					if (random == 3)
						rand = 4;
					else
					{
						rand = 3;
					}
				}
				else
				{
					grid[x][y+1].set_array(grid[x][y].get_array(zx, zy).get_animal, isPlace.first, isPlace.second);
					grid[x][y].set_array(nullptr, zx, zy);
					this->m_age++;
					rand = 4;
				}
			}
		}
		//gauche
		else if (rand == 3)
		{
			//brodure gauche
			if (x == 0)
			{
				isPlace = grid[std::size(grid)-1][y].checkPlaces();
				if (isPlace.first == 4 && isPlace.second == 4)
				{
					if (random == 0)
						rand = 4;
					else
					{
						rand = 0;
					}
				}
				else
				{
					grid[std::size(grid)-1][y].set_array(grid[x][y].get_array(zx, zy).get_animal, isPlace.first, isPlace.second);
					grid[x][y].set_array(nullptr, zx, zy);
					this->m_age++;
					rand = 4;
				}
			}
			else
			{
				isPlace = grid[x-1][y].checkPlaces();
				if (isPlace.first == 4 && isPlace.second == 4)
				{
					if (random == 0)
						rand = 4;
					else
					{
						rand = 0;
					}
				}
				else
				{
					grid[x-1][y].set_array(grid[x][y].get_array(zx, zy).get_animal, isPlace.first, isPlace.second);
					grid[x][y].set_array(nullptr, zx, zy);
					this->m_age++;
					rand = 4;
				}
			}
		}
		else
		{
			std::cerr << "le random n'a pas fonctionner";
			return;
		}
		return;
	}
}
