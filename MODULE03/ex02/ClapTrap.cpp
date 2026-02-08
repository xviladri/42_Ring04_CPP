#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap Default Constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap Parameter Constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) 
{
    std::cout << "ClapTrap Copy Constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) 
{
    std::cout << "ClapTrap Copy Assignment Operator called" << std::endl;
    if (this != &other) 
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap Destructor called for " << _name << std::endl;
}

void ClapTrap::attack(const std::string& target) 
{
    if (_energyPoints > 0 && _hitPoints > 0) 
    {
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target 
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " cannot attack (Low Energy or HP)!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) 
{
    if (_hitPoints > 0) 
    {
        if (amount >= _hitPoints)
            _hitPoints = 0;
        else
            _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount 
                  << " points of damage! Current HP: " << _hitPoints << std::endl;
    } 
    else
        std::cout << "ClapTrap " << _name << " is already down!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) 
{
    if (_energyPoints > 0 && _hitPoints > 0) 
    {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
                  << " points! Current HP: " << _hitPoints << std::endl;
    } 
    else
        std::cout << "ClapTrap " << _name << " cannot repair (Low Energy or HP)!" << std::endl;
}