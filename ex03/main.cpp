#include "HumanA.h"
#include "HumanB.h"
#include <iostream>

int main()
{
    HumanA humanA("Bob", "club");
    HumanB humanB("Jim");

    humanA.attack();
    humanB.attack();

    humanB.setWeapon("crude spiked club");
    humanB.attack();

    return (0);
}