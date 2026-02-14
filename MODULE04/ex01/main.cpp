#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "----------- 1. CREATION ARRAY OF ANIMALS -----------" << std::endl;

    Animal* animals[4];
	int i = 0;
	while (i < 4)
	{
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		i++;
	}
    std::cout << "\n----------- 2. ANIMAL SOUND TESTING -----------" << std::endl;
	i = 0;
	while (i < 4)
	{
        animals[i]->makeSound();
		i++;
	}
	std::cout << "\n---------- 3. DELEATING ANIMALS (Check Destructors) -------" << std::endl;
	i = 0;
	while (i < 4)
	{
		delete animals[i];
		i++;
	}
    std::cout << "\n -------- 4. DEEP COPY TESTING ---------------------------" << std::endl;
	Dog* OriginalDog = new Dog();
	OriginalDog->setBrainIdea(0, "I want food!");
	Dog* CopyDog = new Dog(*OriginalDog);

	std::cout << " [Before] Original: " << OriginalDog->getBrainIdea(0) << std::endl;
	std::cout << " [Before] Copy: " << CopyDog->getBrainIdea(0) << std::endl;
	
	std::cout << "\n----- Modifying the brain of the copy -------" << std::endl;
	CopyDog->setBrainIdea(0, "I want to sleep!");
	
	std::cout << " [After] Original: " << OriginalDog->getBrainIdea(0) << std::endl;
	std::cout << " [After] Copy: " << CopyDog->getBrainIdea(0) << std::endl;
	
	std::cout << "\n----- Deleting copy --------------------------" << std::endl;
	delete CopyDog; 
	std::cout << "\n----- Deleting original ----------------------" << std::endl;
	delete OriginalDog;
    /*Dog basic;
    {
        Dog tmp = basic;
    }*/
    return (0);
}
