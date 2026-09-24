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
		
	/*for (size_t i = 0; i < std::size(tab); i++)
	{
		    if ()
	}*/
	
	return true;
}

void CAnimal::humdrum(std::vector<std::vector<CCase>> grid)
{
	//x: de gauche à droite
    for (int x = 0; x < std::size(grid); x++)
		//y: de haut en bas
        for (int y = 0; y < std::size(grid[x]); y++)
			//zx: array de droite à gauche
            for (int zx = 0; zx < 2; zx++)
				//zy: array de haut en bas
                for (int zy = 0; zy < 2; zy++)
					if(grid[x][y].get_array(zx,zy).get_animal() != nullptr)
						if(grid[x][y].get_array(zx,zy).get_animal().isAlive(grid,x,y)==true)
							grid[x][y].get_array(zx,zy).get_animal().move(grid,x,y,zx,zy);
}

void CAnimal::move(std::vector<std::vector<CCase>> grid, unsigned int x, unsigned int y, unsigned int zx, unsigned int zy)
{
    //0:haut, 1:droite, 2:bas, 3:gauche, dans le sens des aiguille d'une montre en commençant à midi en gros, et 4 c'est la boucle qui s'arrête
    int random = 0;
	std::pair<unsigned int, unsigned int> ischeck;
	while (random == 4)
	{
		//haut
        if (random == 0)
		{
			//bordure haut
            if (y == 0)
			{
				ischeck = grid[x][std::size(grid[x])-1].check();
				if (ischeck.first == 4 && ischeck.second == 4)
					random = 1;
				else
				{
					grid[x][std::size(grid[x])-1].set_array(grid[x][y].get_array(zx, zy).get_animal, ischeck.first, ischeck.second);
					grid[x][y].set_array(nullptr, zx, zy);
					this->m_age++;
					random = 4;
				}
			}
			else
			{
				ischeck = grid[x][y-1].check();
				if (ischeck.first == 4 && ischeck.second == 4)
					random = 1;
				else
				{
					grid[x][y-1].set_array(grid[x][y].get_array(zx, zy).get_animal, ischeck.first, ischeck.second);
					grid[x][y].set_array(nullptr, zx, zy);
					this->m_age++;
					random = 4;
				}
			}
		}
		//droite
        else if (random == 1)
		{
			//bordure droite
            if (x == std::size(grid)-1)
			{
				ischeck = grid[0][y].check();
				if (ischeck.first == 4 && ischeck.second == 4)
					random = 2;
				else
				{
					grid[0][y].set_array(grid[x][y].get_array(zx, zy).get_animal, ischeck.first, ischeck.second);
					grid[x][y].set_array(nullptr, zx, zy);
					this->m_age++;
					random = 4;
				}
			}
			else
			{
				ischeck = grid[x][y-1].check();
				if (ischeck.first == 4 && ischeck.second == 4)
					random = 2;
				else
				{
					grid[x][y-1].set_array(grid[x][y].get_array(zx, zy).get_animal, ischeck.first, ischeck.second);
					grid[x][y].set_array(nullptr, zx, zy);
					this->m_age++;
					random = 4;
				}
			}
		}
		//bas
        else if (random == 2)
		{
			//bordure bas
            if (y == std::size(grid[x])-1)
			{
				ischeck = grid[x][0].check();
				if (ischeck.first == 4 && ischeck.second == 4)
					random = 3;
				else
				{
					grid[x][0].set_array(grid[x][y].get_array(zx, zy).get_animal, ischeck.first, ischeck.second);
					grid[x][y].set_array(nullptr, zx, zy);
					this->m_age++;
					random = 4;
				}
			}
			else
			{
				ischeck = grid[x][y+1].check();
				if (ischeck.first == 4 && ischeck.second == 4)
					random = 3;
				else
				{
					grid[x][y+1].set_array(grid[x][y].get_array(zx, zy).get_animal, ischeck.first, ischeck.second);
					grid[x][y].set_array(nullptr, zx, zy);
					this->m_age++;
					random = 4;
				}
			}
		}
		//gauche
        else if (random == 3)
		{
			//brodure gauche
            if (x == 0)
			{
				ischeck = grid[std::size(grid)-1][y].check();
				if (ischeck.first == 4 && ischeck.second == 4)
					random = 0;
				else
				{
					grid[std::size(grid)-1][y].set_array(grid[x][y].get_array(zx, zy).get_animal, ischeck.first, ischeck.second);
					grid[x][y].set_array(nullptr, zx, zy);
					this->m_age++;
					random = 4;
				}
			}
			else
			{
				ischeck = grid[x-1][y].check();
				if (ischeck.first == 4 && ischeck.second == 4)
					random = 3;
				else
				{
					grid[x-1][y].set_array(grid[x][y].get_array(zx, zy).get_animal, ischeck.first, ischeck.second);
					grid[x][y].set_array(nullptr, zx, zy);
					this->m_age++;
					random = 4;
				}
			}
		}
        else
		{
            std::cerr << "le random n'a pas fonctionner";
			return ;
		}
	}
	return ;
}

std::pair<unsigned int, unsigned int> CAnimal::check() const
{
	return std::pair<unsigned int, unsigned int>(4, 4);
}
