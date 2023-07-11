/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:22:28 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 02:00:24 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
    std::cout << this->type << " constructor called" << std::endl;
}

WrongCat::~WrongCat( void )
{
    std::cout << this->type << " destructor called" << std::endl;
}

void    WrongCat::makeSound( void ) const
{
    std::cout << "Meow!" << std::endl;
}