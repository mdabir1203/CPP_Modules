#include "HumanA.h"
#include <iostream>

/**
 * Here I separated the interface from the implementation for better organization
 */

HumanA::HumanA(std::string& humanName, const std::string& weaponType)
                    : name(humanName), weapon() {
    weapon.setType(weaponType);
}

void HumanA::attack()
{
    std::cout << name << "attacks with the" << weapon.getType() << std::endl;
}
