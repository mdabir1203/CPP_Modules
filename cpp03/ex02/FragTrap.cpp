/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 01:11:22 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/07 12:14:17 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
	std::cout << *this << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap & src) : ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
	std::cout << *this << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
	std::cout << *this << std::endl;
	return ;
}

FragTrap & FragTrap::operator=(const FragTrap & rhs)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return (*this);
}

/* void FragTrap::attack(std::string const & target)
{
	if (this->energyPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout	<< this->name
					<< " smacks " << target
					<< ", causing " << this->attackDamage
					<< " points of damage!" << std::endl;
	}
	else
		std::cout	<< this->name
					<< "'s energy's gone!" << std::endl;
} */

void FragTrap::highFivesGuys()
{
	std::cout << "High five guys" << std::endl;
	return ;
}

#endif
