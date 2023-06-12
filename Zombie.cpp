/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:29:41 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/09 00:33:07 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

/**
 * First need to implement constructor and destructor 
 * Next printing message for zombie class 
 */

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << "removing Zombie: " << name << std::endl;
}

void Zombie::announce(void)
{
    std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}