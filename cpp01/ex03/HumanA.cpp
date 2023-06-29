/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:44:12 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/28 09:42:26 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

/*
*For the HumanA reference is more efficient and safer than a pointer.
 As the humanA will always have a weapon. References are like an alias for an object.
*/ 
HumanA::HumanA(const std::string& humanName, Weapon& weapon) : name(humanName), weapon(weapon) {}

void HumanA::attack() const
{
    std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}



