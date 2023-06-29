/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:03:09 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/28 09:44:04 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/**
 *HumanB may not always have a weapon. So better using a pointer 
 *which allowws for the possibility of changing the object assocciated with 
  the humanB obj at runtime, not possible with reference 
 */
HumanB::HumanB(const std::string& humanName) : name(humanName), weaponType(NULL) {}

void HumanB::setWeapon(Weapon& newWeapon)
{
    weaponType = &newWeapon;
}

void HumanB::attack() const
{
    if (weaponType != NULL)
        std::cout << name << " attacks with their " << weaponType->getType() << std::endl;
    else
        std::cout << name << " attacks with their bare hands" << std::endl;
}
