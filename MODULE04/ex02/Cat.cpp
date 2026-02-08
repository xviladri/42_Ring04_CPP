#include "Cat.hpp"

Cat::Cat() 
{
    this->type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other) 
{
    this->_brain = new Brain(*other._brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) 
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        AAnimal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat() 
{
    delete this->_brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const 
{
    std::cout << "Meow!" << std::endl;
}

Brain* Cat::getBrain() const 
{
    return this->_brain;
}