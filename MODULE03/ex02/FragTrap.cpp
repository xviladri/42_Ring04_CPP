#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() 
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap Default Constructor called for " << this->_name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap Parameter Constructor called for " << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) 
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) 
{
    std::cout << "FragTrap Copy Assignment Operator called" << std::endl;
    if (this != &other) 
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() 
{
    std::cout << "FragTrap Destructor called for " << this->_name << std::endl;
}

void FragTrap::highFivesGuys(void) 
{
    std::cout << "FragTrap " << this->_name << " requests a positive high five! ✋" << std::endl;
}