#pragma once
#include "CAnimal.h"

class CWolf : public CAnimal
{
public :
    void m_displacement_mortality_rate();
    CWolf(float speed, float reproduction_rate, float mortality_rate, float age, float life_expectancy, float gender, float time_before_reproduction, float hunger);
};

//constructeur
CWolf::CWolf(float speed, float reproduction_rate, float mortality_rate, float age, 
             float life_expectancy, float gender, float time_before_reproduction, float hunger)
{
    CAnimal::set_speed(speed);
    CAnimal::set_reproduction_rate(reproduction_rate);
    CAnimal::set_mortality_rate(mortality_rate);
    CAnimal::set_age(age);
    CAnimal::set_life_expectancy(life_expectancy);
    CAnimal::set_gender(gender);
    CAnimal::set_time_before_reproduction(time_before_reproduction);
    CAnimal::set_hunger(hunger);
}