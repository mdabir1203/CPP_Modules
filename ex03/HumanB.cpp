#include "HumanB.h"
#include <iostream>

HumanB::HumanB(const std::string& humanName) : name(humanName), weaponPresent(false) {}

void HumanB::hasWeapon(const std::string &chooseWeapon) {
    weaponPresent = true;
    str::cout << name << "acquires a weapon" << humanWeapon << std::endl;
}

void HumanB::attack() {
    if (hasWeapon)
    {
        std::cout << name << "attacks with the weapon" << std::endl;
    }
    else
    {
        std::cout << name << "attacks without any weapons " << std::endl;
    }
}
