#include "ScavTrap.hpp"

int main() 
{
    std::cout << "--- Test 1: ScavTrap Construction ---" << std::endl;
    ScavTrap scav1("Guardian");
    ScavTrap scav2("Gatekeeper");

    std::cout << "\n--- Test 2: ScavTrap Attack ---" << std::endl;
    scav1.attack("Intruder");

    std::cout << "\n--- Test 3: Guard Gate ---" << std::endl;
    scav1.guardGate();

    std::cout << "\n--- Test 4: Copy ---" << std::endl;
    ScavTrap scav3(scav1);
    scav3.guardGate();

    std::cout << "\n--- Destruction ---" << std::endl;
    return 0;
}
