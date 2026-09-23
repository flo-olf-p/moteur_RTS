#pragma once

class CAnimal{
    /*members--------------------------------------------------*/
private:
	int animal_param_id;
    float m_speed;
    float m_reproduction_rate;
    float m_mortality_rate;
    float m_age;
    float m_life_expectancy;
    float m_gender;
    float m_time_before_reproduction;
    float m_hunger;
    float m_time_before_hunger;
    std::pair<int,int> m_location;
    
public:
    /*const------------------------------------------------------*/
    CAnimal(float speed, float reproduction_rate, float mortality_rate, float age,
        float life_expectancy, float gender, float time_before_reproduction, float hunger);

    /*GET------------------------------------------------------*/
    float get_speed(){return m_speed;}
    float get_reproduction_rate(){return m_reproduction_rate;}
    float get_mortality_rate(){return m_mortality_rate;}
    float get_age(){return m_age;}
    float get_life_expectancy(){return m_life_expectancy;}
    float get_gender(){return m_gender;};
    float get_time_before_reproduction(){return m_time_before_reproduction;}
    float get_hunger(){return m_hunger;}
    float get_time_before_hunger(){return m_time_before_hunger;}
    std::pair<int,int> get_location(){return m_location;}
    
    /*SET------------------------------------------------------*/
    void set_speed(float speed){m_speed = speed;}
    void set_reproduction_rate(float reproduction_rate){m_reproduction_rate = reproduction_rate;}
    void set_mortality_rate(float mortality_rate){m_mortality_rate = mortality_rate;}
    void set_age(float age){m_age = age; }
    void set_life_expectancy(float life_expectancy){m_life_expectancy = life_expectancy;}
    void set_gender(float gender){m_gender = gender;}
    void set_time_before_reproduction(float time_before_reproduction){m_time_before_reproduction = time_before_reproduction;}
    void set_hunger(float hunger){m_hunger = hunger;}
    void set_time_before_hunger(float time_before_hunger){m_time_before_hunger = time_before_hunger;}
    void set_location(std::pair<int,int> location){m_location = location;}
    
    /*FUNCTION-------------------------------------------------*/
    bool Alive();
	void story();
protected:
    /*members--------------------------------------------------*/
    float m_speed;
    float m_reproduction_rate;
    float m_mortality_rate;
    float m_age;
    float m_life_expectancy;
    float m_gender;
    float m_time_before_reproduction;
    float m_hunger;
    void shift();
};