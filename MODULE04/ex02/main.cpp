#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
//	Animal* test = new Animal();
	const Animal* Vera = new Dog();
    const Animal* Tay = new Cat();

	Vera->makeSound();
	Tay->makeSound();

    delete Vera;
    delete Tay;

    return (0);
}
