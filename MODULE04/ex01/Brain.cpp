#include "Brain.hpp"

Brain::Brain() 
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) 
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other) 
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    int	i;
    
    i = 0;
    if (this != &other) 
    {
        while (i < 100)
        {
            this->_ideas[i] = other._ideas[i];
            i++;
        }
    }
    return (*this);
}
Brain::~Brain() 
{
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int i) const
{
    if (i >= 0 && i < 100)
        return (this->_ideas[i]);
    return ("");
}

void Brain::setIdea(int i, const std::string& idea)
{
    if (i >= 0 && i < 100)
        this->_ideas[i] = idea;
}
