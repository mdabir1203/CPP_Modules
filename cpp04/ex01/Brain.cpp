/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:18:57 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 01:42:45 by mabbas           ###   ########.fr       */
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
    std::cout << "<Brain.cpp:32> Brain copy is summoned." << std::endl;
    if ( this != &src ) {
        for ( int i = 0; i < 100; i++ ) {
            this->_ideas[i] = src._ideas[i];
        }
    }
    return *this;
}
