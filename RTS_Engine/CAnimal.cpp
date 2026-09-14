public class CAnimal
{
    /*members--------------------------------------------------*/
    private float m_speed;
    private float m_reproduction_rate;
    private float m_mortality_rate;
    private float m_age;
    private float m_life_expectancy;
    private float m_gender;
    private float m_time_before_reproduction;
    private float m_hunger;
    
    /*GET------------------------------------------------------*/
    public float get_speed(){return m_speed;};
    public float get_reproduction_rate(){return m_reproduction_rate;};
    public float get_mortality_rate(){return m_mortality_rate;};
    public float get_age(){return m_age;};
    public float get_life_expectancy(){return m_life_expectancy;};
    public float get_gender(){return m_gender;};
    public float get_time_before_reproduction(){return m_time_before_reproduction;};
    public float get_hunger(){return m_hunger;};
    
    /*SET------------------------------------------------------*/
    public void set_speed(float speed){m_speed = speed;};
    public void set_reproduction_rate(float reproduction_rate){m_reproduction_rate = reproduction_rate;};
    public void set_mortality_rate(float mortality_rate){m_mortality_rate = mortality_rate};
    public void set_age(float age){m_age = age};
    public void set_life_expectancy(float life_expectancy){m_life_expectancy = life_expectancy};
    public void set_gender(float gender){m_gender = gender};
    public void set_time_before_reproduction(float time_before_reproduction){m_time_before_reproduction = time_before_reproduction};
    public void set_hunger(float hunger){m_hunger = hunger};
    
    /*FUNCTION-------------------------------------------------*/
    public bool Alive()
    protected void shift();
};