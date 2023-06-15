/**
* Usage of Pointer:
    * Polymorphism+dynamic binding
    * Optional Presence:
    * Reassignability:
    * Object Ownership and Lifetime:
    * Function parameters and return values:

 * Usage of Reference:
    *Simplicity and Readability and object existence guaranteed
* Passing Optional Objects or allow null values:-> Use pointer
*/

#include "Weapon.h"

Weapon::Weapon(const std::string& weaponType) : type(weaponType) {}

const std::string Weapon::get_type() const {
    return type;
}

void Weapon::set_type(std::string& chosenType) {
     type = chosenType;
}
