/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:27:46 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/06 22:41:17 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() 
{
    ClapTrap clapTrap1("Messi");
    clapTrap1.attack("Ronaldo", 7);
    clapTrap1.takeDamage(3);
    clapTrap1.beRepaired(1);

    ClapTrap clapTrap2("Zidane");
    clapTrap2.attack("Figo", 7);
    clapTrap2.takeDamage(4);
    clapTrap2.beRepaired(3);

    return 0;
}
