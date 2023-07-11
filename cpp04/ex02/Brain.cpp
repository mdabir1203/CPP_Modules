/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:21:14 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 02:03:15 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "Brain created." << std::endl;
}

Brain::~Brain( void )
{
    std::cout << "Brain destroyed." << std::endl;
}

Brain::Brain( const Brain& src )
{
    *this = src;
}

Brain& Brain::operator=( const Brain& src )
{
    std::cout << "Brain copy called." << std::endl;
    int i = 0;
    if ( this != &src ) 
    {
        while ( i < 100 ) 
        {
            this->ideas[i] = src.ideas[i];
            i++;
        }
    
    }
    return *this;
}
