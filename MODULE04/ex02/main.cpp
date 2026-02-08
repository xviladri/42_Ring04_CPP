#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // AAnimal test; // This should fail compilation if uncommented
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    delete j;
    delete i;

    std::cout << "---------------------------------" << std::endl;

    //Same leak test as Ex01
    AAnimal* animals[4];

    for (int k = 0; k < 2; k++)
        animals[k] = new Dog();
    for (int k = 2; k < 4; k++)
        animals[k] = new Cat();

    for (int k = 0; k < 4; k++)
        animals[k]->makeSound();

    for (int k = 0; k < 4; k++)
        delete animals[k];

    return 0;
}