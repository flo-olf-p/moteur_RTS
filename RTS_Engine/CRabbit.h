#pragma once
#include "CAnimal.h"

class CRabbit : public CAnimal
{
public :
    void m_displacement_mortality_rate();
    CRabbit(float speed, float reproduction_rate, float mortality_rate, float age, float life_expectancy, float gender, float time_before_reproduction, float hunger);
};

//constructeur
CRabbit::CRabbit(float speed, float reproduction_rate, float mortality_rate, float age, 
             float life_expectancy, float gender, float time_before_reproduction, float hunger)
    : CAnimal(speed, reproduction_rate, mortality_rate, age,
        life_expectancy, gender, time_before_reproduction, hunger)
{

}