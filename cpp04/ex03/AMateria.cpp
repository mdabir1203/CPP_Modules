/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:22:41 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 02:27:48 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : type("")
{
    // std::cout << "* AMateria: materia is created *" << std::endl;
}

AMateria::AMateria( std::string const & type )  : type(type)
{
    std::cout << "AMateria " << this->type << " created" << std::endl;
}

AMateria::AMateria( AMateria const & src )
{
    *this = src;
}

AMateria::~AMateria( void )
{
    std::cout << "AMateria " << this->type << " destroyed" << std::endl;
}

std::string const & AMateria::getType() const
{
    return this->type;
}

AMateria* AMateria::clone() const
{
    return (AMateria*)this;
}

void    AMateria::use( ICharacter& target )
{
    std::cout << "AMateria " << this->type << " used on " << target.getName() << std::endl;
}

