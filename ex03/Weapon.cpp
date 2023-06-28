/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:45:05 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/28 00:24:16 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include "Weapon.hpp"

Weapon::Weapon(const std::string& weaponType) : type(weaponType) {}

const std::string Weapon::getType() const {
    return type;
}

void Weapon::setType(const std::string& chosenType) {
     type = chosenType;
}
