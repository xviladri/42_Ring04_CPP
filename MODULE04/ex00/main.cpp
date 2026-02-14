#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* Vera = new Dog();
    const Animal* Tay = new Cat();

    std::cout << Vera->getType() << " " << std::endl;
    std::cout << Tay->getType() << " " << std::endl;
    Vera->makeSound();
    Tay->makeSound();
    meta->makeSound();

    delete meta;
    delete Vera;
    delete Tay;

    std::cout << "----------------- WRONG CLASS ----------------" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;

    return (0);
}
