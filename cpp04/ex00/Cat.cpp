/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:14:11 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 01:17:34 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
    std::cout << this->type << " constructor is summoned" << std::endl;
}

Cat::~Cat( void )
{
    std::cout << this->type << " destructor is summoned" << std::endl;
}

void    Cat::makeSound( void ) const
{
    std::cout << "Meow!" << std::endl;
}