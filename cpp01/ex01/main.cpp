/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:37:50 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/22 23:56:38 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombieHorde.hpp"

int main()
{
    Zombie* horde1 = zombieHorde(10, "curiel");
    for (int i = 0; i < 5; i++)
    {
        horde1[i].announce();
    }
    delete[] horde1;
    
    Zombie* horde2 = zombieHorde(3, "charlie");
    for (int j = 0; j < 3; j++)
    {
        horde2[j].announce();
    }
    delete[] horde2;

    Zombie* horde3 = zombieHorde(0, "Trapped");
    if (horde3 == NULL)
        std::cout << "No zombies made" << std::endl;
    else
        delete[] horde3;
    return (0);
}

