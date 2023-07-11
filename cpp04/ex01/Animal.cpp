/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:18:45 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 01:42:45 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type( "Animel" ) {
    std::cout << this->type << " constructor is summoned" << std::endl;
}

Animal::Animal( std::string type ) : type( type )
{
    std::cout << "Animal " << this->type << " constructor is summoned" << std::endl;
}

Animal::~Animal( void )
{
    std::cout << "Animal destructor is summoned" << std::endl;
}

Animal::Animal( const Animal& src )
{
    std::cout << "Animal copy constructor is summoned" << std::endl;
    *this = src;
}

Animal& Animal::operator=( const Animal& rhs )
{
    std::cout << "<Animal.cpp:35: Animal assignment operator is summoned" << std::endl;
    if ( this != &rhs ) {
        this->type = rhs.type;
    }
    return *this;
}

void Animal::makeSound( void ) const
{
    std::cout << "Animal makeSound is summoned" << std::endl;
}

std::string    Animal::getType( void ) const
{
    return this->type;
}