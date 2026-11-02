#pragma once
#include "CAnimal.h"

class CRabbit : public CAnimal
{
public:
    //void m_displacement_mortality_rate();
    
    CRabbit(unsigned int speed, float reproduction_rate, float mortality_rate, unsigned int life_expectancy, unsigned int reproduction_delay, unsigned int hunger_delay)
        : CAnimal{ speed, reproduction_rate, mortality_rate, life_expectancy, reproduction_delay, hunger_delay} {};

    void move() override;
};