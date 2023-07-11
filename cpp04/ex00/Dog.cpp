/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:14:27 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 01:17:34 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" )
{
    std::cout << this->type << " constructor is summoned" << std::endl;
}

Dog::~Dog( void )
{
    std::cout << this->type << " destructor is summoned" << std::endl;
}

void    Dog::makeSound( void ) const
{
    std::cout << "Woof!" << std::endl;
}