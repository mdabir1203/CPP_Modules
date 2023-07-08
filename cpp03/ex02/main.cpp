/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:29:31 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/08 12:29:39 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap bar("bar");
	FragTrap baz("baz");
	ClapTrap foo(bar);
	
	foo.setName("foo");
	foo.setAttackDamage(7);

	std::cout << std::endl << foo << bar << std::endl;

	foo.attack(bar.getName());
	bar.takeDamage(foo.getAttackDamage());

	std::cout << std::endl << foo << bar << std::endl;

	bar.beRepaired(5);

	std::cout << std::endl << foo << bar << std::endl;

	bar.guardGate();
	baz.highFivesGuys();

	std::cout << std::endl;

	return (0);
}

