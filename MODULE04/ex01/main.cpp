#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;

    std::cout << "---------------------------------" << std::endl;

    Animal* animals[4];

    for (int k = 0; k < 2; k++)
        animals[k] = new Dog();
    for (int k = 2; k < 4; k++)
        animals[k] = new Cat();

    for (int k = 0; k < 4; k++)
        animals[k]->makeSound();

    for (int k = 0; k < 4; k++)
        delete animals[k];

    std::cout << "---------------------------------" << std::endl;
    
    Dog basic;// Deep copy test
    {
        Dog tmp = basic;
    } // tmp is destroyed, basic should still work if deep copy

    return 0;
}