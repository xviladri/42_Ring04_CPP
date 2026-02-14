#include "Cat.hpp"

Cat::Cat() 
{
	type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) 
{
        this->_brain = new Brain(*other._brain);
        std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) 
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        this->type = other.type;//esto es lo mismo que hacer: Animmal::operator=(other);
        if (this->_brain != NULL)
            delete this->_brain;
        this->_brain = new Brain(*other._brain);//creamos uno nuevo copiando del otro
    }
    return (*this);
}

Cat::~Cat() 
{
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const 
{
    std::cout << "Cat makes sound: Miau miau!" << std::endl;
}

void Cat::setBrainIdea(int i, const std::string& idea)
{
    if (i >= 0 && i < 100 && idea != "")
        this->_brain->setIdea(i, idea);
    else if (idea == "")
        std::cout << "Please write a correct idea" << std::endl;
    else
        std::cout << "Please write a valid index" << std::endl;
}

std::string Cat::getBrainIdea(int i) const
{
    if (i >= 0 && i < 100)
        return (this->_brain->getIdea(i));
    else
    {
        std::cout << "Please write a valid index" << std::endl;
        return ("");
    }
}
