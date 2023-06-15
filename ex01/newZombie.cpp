/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:33:25 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/12 14:28:53 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/** allocate memory
 * call constructor with name as parameter
 * return pointer to zombie
 */
Zombie* newZombie(std::string name)
{
    Zombie*zombie = new Zombie(name);
    return (zombie);
}





