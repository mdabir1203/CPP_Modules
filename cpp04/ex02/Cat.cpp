/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:21:25 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 02:13:03 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : AAnimal("Cat") {
    std::cout << this->type << " constructor called" << std::endl;
    try {
        this->brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Memory Allocation is failed : " << std::endl;
    }
}

Cat::~Cat( void )
{
    std::cout << this->type << " destructor called" << std::endl;
    delete  this->brain;
}

void    Cat::makeSound( void ) const
{
    std::cout << "Meow!" << std::endl;
}

Cat::Cat( const Cat& src ) : AAnimal(src)
{
    *this = src;
}

Cat& Cat::operator=( const Cat& src )
{
    std::cout << "Cat copy called." << std::endl;
    if (this != &src)
    {
        this->type = src.type;
        this->brain = new Brain(*src.brain);
    }
    return *this;
}