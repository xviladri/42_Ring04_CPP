#include "Zombie.hpp"

int main(void)
{
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    
    randomChump("StackZombie");//this zombie dies inside the function.
    
    delete heapZombie;//this zombie only dies when we delete it.
    return (0);
}
