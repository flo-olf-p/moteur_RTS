#pragma once
#include <vector>
//#include <utility> //std::pair

class CAnimal
{
protected:
    unsigned int m_speed;
    float m_reproduction_rate;
    float m_mortality_rate;
    unsigned int m_age = 0;
    unsigned int m_life_expectancy;
    //float m_gender;
    unsigned int m_reproduction_delay;
    unsigned int m_hunger = 10;
    unsigned int m_hunger_delay;
    //std::pair<int,int> m_location; Plutot un CTile* ? Classe à faire
    
public:

    CAnimal(unsigned int speed, float reproduction_rate, float mortality_rate,
        unsigned int life_expectancy, unsigned int reproduction_delay, unsigned int hunger_delay);

    /*GETTERS------------------------------------------------------*/
    unsigned int get_speed() const {return m_speed;}
    float get_reproduction_rate() const {return m_reproduction_rate;}
    float get_mortality_rate() const {return m_mortality_rate;}
    unsigned int get_age() const {return m_age;}
    unsigned int get_life_expectancy() const {return m_life_expectancy;}
    //float get_gender(){return m_gender;};
    unsigned int get_reproduction_delay() const {return m_reproduction_delay;}
    unsigned int get_hunger()const {return m_hunger;}
    unsigned int get_hunger_delay()const {return m_hunger_delay;}
    //std::pair<int,int> get_location(){return m_location;}
    
    /*SETTERS------------------------------------------------------*/
    void set_speed(unsigned int speed){m_speed = speed;}
    void set_reproduction_rate(float reproduction_rate){m_reproduction_rate = reproduction_rate;}
    void set_mortality_rate(float mortality_rate){m_mortality_rate = mortality_rate;}
    void set_age(unsigned int age){m_age = age; }
    void set_life_expectancy(unsigned int life_expectancy){m_life_expectancy = life_expectancy;}
    //void set_gender(float gender){m_gender = gender;}
    void set_reproduction_delay(unsigned int reproduction_delay){m_reproduction_delay = reproduction_delay;}
    void set_hunger(unsigned int hunger){m_hunger = hunger;}
    void set_hunger_delay(unsigned hunger_delay){m_hunger_delay = hunger_delay;}
    //void set_location(std::pair<int,int> location){m_location = location;}
    
    /*FUNCTIONS------------------------------------------------------*/
    bool isAlive(std::vector<std::vector<CCase>> grid, unsigned int x, unsigned int y) const;
	//void story() const;
    virtual void move(std::vector<std::vector<CCase>> grid, unsigned int x, unsigned int y, unsigned int zx, unsigned int zy) =0; 
    
    virtual void humdrum(std::vector<std::vector<CCase>> grid);
    
    std::pair<unsigned int, unsigned int> check();
};