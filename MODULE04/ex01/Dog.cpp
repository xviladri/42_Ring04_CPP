#include "Dog.hpp"

Dog::Dog() 
{
	type = "Dog";
	_brain = new Brain();
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
        this->type = other.type;//esto es lo mismo que hacer: Animmal::operator=(other);
        if (this->_brain != NULL)
            delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return (*this);
}

Dog::~Dog() 
{
    delete this->_brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const 
{
    std::cout << "Dog makes sound: Woof woof!" << std::endl;
}

void Dog::setBrainIdea(int i, const std::string& idea)
{
    if (i >= 0 && i < 100 && idea != "")
        this->_brain->setIdea(i, idea);
    else if (idea == "")
        std::cout << "Please write a correct idea" << std::endl;
    else
        std::cout << "Please write a valid index" << std::endl;
}

std::string Dog::getBrainIdea(int i) const
{
    if (i >= 0 && i < 100)
        return (this->_brain->getIdea(i));
    else
    {
        std::cout << "Please write a valid index" << std::endl;
        return ("");
    }
}
