/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 01:11:07 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/07 01:22:26 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

#define CYAN    "\033[36m"
#define RESET   "\033[0m"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : 	name(name),
										hitPoints(10),
										energyPoints(10),
										attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	std::cout << *this << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
	std::cout << *this << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
	std::cout << *this << std::endl;
	return ;
}

ClapTrap & ClapTrap::operator=(const ClapTrap & rhs)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(std::string const & target)
{
	if (this->energyPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout	<< this->name
					<< " attacks " << target
					<< ", causing " << this->attackDamage
					<< " points of damage!" << std::endl;
	}
	else
		std::cout	<< this->name
					<< " is out of energy!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout	<< this->name
				<< " takes " << amount
				<< " points of damage!" << std::endl;
	if (amount > this->hitPoints)
		amount = this->hitPoints;
	this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0)
	{
		this->hitPoints += amount;
		this->energyPoints -= 1;
		std::cout	<< this->name
					<< " is repaired by " << amount
					<< " points!" << std::endl;
	}
	else
		std::cout	<< this->name
					<< " is out of energy!" << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return (this->name);
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return (this->hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return (this->energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return (this->attackDamage);
}

void ClapTrap::setName(std::string name)
{
	std::cout	<< this->name
				<< " name changed to " << name << std::endl;
	this->name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
	this->hitPoints = hitPoints;
	std::cout 	<< this->name
				<< " hit points set to " << hitPoints << std::endl;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->energyPoints = energyPoints;
	std::cout 	<< this->name
				<< " energy points set to " << energyPoints << std::endl;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	this->attackDamage = attackDamage;
	std::cout 	<< this->name
				<< " attack damage set to " << attackDamage << std::endl;
}

std::ostream & operator<<(std::ostream & o, ClapTrap const & rhs)
{
	o	<< CYAN << rhs.getName() << ": "
		<< "HP: " << rhs.getHitPoints() << ", "
		<< "EP: " << rhs.getEnergyPoints() << ", "
		<< "AD: " << rhs.getAttackDamage() << RESET <<  std::endl;
	return (o);
}














