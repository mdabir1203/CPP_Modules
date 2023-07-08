/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:27:16 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/06 22:27:32 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
 
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " is created." << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " is destroyed." << std::endl;
}

void ClapTrap::attack(std::string const & target, unsigned int amount) {
    if (energyPoints < 1) {
        std::cout << "ClapTrap " << name << " has no energy to attack." << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << amount << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints < amount) {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " is out of hit points." << std::endl;
    } else {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints < 1) {
        std::cout << "ClapTrap " << name << " has no energy to repair." << std::endl;
        return;
    }
    energyPoints--;
    hitPoints = std::min(hitPoints + amount, 10u);
    std::cout << "ClapTrap " << name << " is repaired for " << amount << " points." << std::endl;
}
