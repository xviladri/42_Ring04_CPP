#include "ClapTrap.hpp"

int main() 
{
    std::cout << "--- Test 1: Basic Construction ---" << std::endl;
    ClapTrap bot1("Bot1");
    ClapTrap bot2("Bot2");

    std::cout << "\n--- Test 2: Attack and Repair ---" << std::endl;
    bot1.attack("Bot2");
    bot2.takeDamage(0);// Takes 0 damage based on Ex00 specs for attack damage init 0
    bot1.beRepaired(5);

    std::cout << "\n--- Test 3: Exhaustion ---" << std::endl;
    // Drain energy
    for (int i = 0; i < 10; ++i)
        bot1.attack("Dummy");
    bot1.attack("Should Fail");
    bot1.beRepaired(10);//Should fail

    std::cout << "\n--- Test 4: Death ---" << std::endl;
    bot2.takeDamage(20);
    bot2.attack("Zombie");// Should fail
    bot2.beRepaired(10);// Should fail

    std::cout << "\n--- Test 5: Copy ---" << std::endl;
    ClapTrap bot3(bot1);
    bot3.attack("CopyCat");

    std::cout << "\n--- Destruction ---" << std::endl;
    return 0;
}
