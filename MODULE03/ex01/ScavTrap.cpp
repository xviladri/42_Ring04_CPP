#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap Default Constructor called for " << this->_name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap Parameter Constructor called for " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) 
{
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) 
{
    std::cout << "ScavTrap Copy Assignment Operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap Destructor called for " << this->_name << std::endl;
}

void ScavTrap::attack(const std::string& target) 
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0) 
    {
        this->_energyPoints--;
        std::cout << "ScavTrap " << this->_name << " brutally attacks " << target 
                  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    } 
    else
        std::cout << "ScavTrap " << this->_name << " cannot attack (Low Energy or HP)!" << std::endl;
}

void ScavTrap::guardGate() 
{
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}