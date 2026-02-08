#include "FragTrap.hpp"

int main() 
{
    std::cout << "--- Test 1: FragTrap Construction ---" << std::endl;
    FragTrap frag1("Buddy");
    FragTrap frag2("Pal");

    std::cout << "\n--- Test 2: FragTrap Attack (Inherited) ---" << std::endl;
    frag1.attack("Enemy"); // Should do 30 dmg
    frag2.takeDamage(30);

    std::cout << "\n--- Test 3: High Fives ---" << std::endl;
    frag1.highFivesGuys();

    std::cout << "\n--- Test 4: Copy ---" << std::endl;
    FragTrap frag3(frag1);
    frag3.highFivesGuys();

    std::cout << "\n--- Destruction ---" << std::endl;
    return 0;
}