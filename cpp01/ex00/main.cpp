#include "Zombie.hpp"
int main()
{
    Zombie *zombieA = newZombie("Linux");
    zombieA->announce();
    delete zombieA;

    randomChump("Windows"); // stack memory
    return (0);
}
