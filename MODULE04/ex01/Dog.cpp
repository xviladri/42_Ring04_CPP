#include "Dog.hpp"

Dog::Dog() 
{
    this->type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) 
{
    this->_brain = new Brain(*other._brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) 
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        Animal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog() 
{
    delete this->_brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const 
{
    std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const 
{
    return this->_brain;
}