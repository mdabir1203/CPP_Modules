/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:20:25 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 01:42:45 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type( "WrongAnimel" ) {
    std::cout << this->type << " constructor is summoned" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : type( type )
{
    std::cout << "WrongAnimal " << this->type << " constructor is summoned" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal destructor is summoned" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& src )
{
    std::cout << "WrongAnimal copy constructor is summoned" << std::endl;
    *this = src;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& rhs )
{
    std::cout << "WrongAnimal assignment operator is summoned" << std::endl;
    if ( this != &rhs ) {
        this->type = rhs.type;
    }
    return *this;
}

void WrongAnimal::makeSound( void ) const
{
    std::cout << "WrongAnimal makeSound is summoned" << std::endl;
}

std::string    WrongAnimal::getType( void ) const
{
    return this->type;
}