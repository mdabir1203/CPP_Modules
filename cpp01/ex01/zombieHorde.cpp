/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:30:34 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/23 00:01:16 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** 
 * 
*/
#include "zombieHorde.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    int i = 0;
    Zombie* horde = new Zombie[N];
    while (i < N)
    {
        horde[i] = Zombie(name);
        i++;
    }
    return (horde);
}
