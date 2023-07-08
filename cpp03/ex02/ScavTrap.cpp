/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 01:21:01 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/07 11:56:54 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
	std::cout << *this << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap & src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
	std::cout << *this << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
	std::cout << *this << std::endl;
	return ;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & rhs)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return (*this);
}

void ScavTrap::attack(std::string const & target)
{
	if (this->energyPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout	<< this->name
					<< " hits " << target
					<< ", causing " << this->attackDamage
					<< " points of damage!" << std::endl;
	}
	else
		std::cout	<< this->name
					<< " has no energy left!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout	<< this->name
				<< " is now in Gate keeper mode."
				<< std::endl;
}

#endif
