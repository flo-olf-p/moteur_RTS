#pragma once
#include "CAnimal.h"


#include <iostream>
#include <vector>
#include <random>

class CRabbit : public CAnimal
{
public:
    
    CRabbit(unsigned int speed, float reproduction_rate, float mortality_rate, unsigned int life_expectancy, unsigned int reproduction_delay, unsigned int hunger_delay, bool is_Carnivorous)
        : CAnimal{ speed, reproduction_rate, mortality_rate, life_expectancy, reproduction_delay, hunger_delay, is_Carnivorous } {};

    void move(std::vector<std::vector<CTile>> grid, unsigned int x, unsigned int y, unsigned int zx, unsigned int zy) override;
};