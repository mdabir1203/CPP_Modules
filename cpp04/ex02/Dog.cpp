/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:21:37 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 02:14:13 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog")
{
    std::cout << this->type << " constructor called" << std::endl;
    try {
        this->brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Memory Allocation is failed : " << std::endl;
    }
}

Dog::~Dog( void )
{
    delete  this->brain;
    std::cout << this->type << " destructor called" << std::endl;
}

void    Dog::makeSound( void ) const
{
    std::cout << "Woof!" << std::endl;
}

Dog::Dog( const Dog& src ) : AAnimal(src)
{
    *this = src;
}

Dog& Dog::operator=(const Dog& src)
{
    std::cout << "Dog copy called." << std::endl;
    if (this != &src)
    {
        this->type = src.type;
        this->brain = new Brain(*src.brain);
    }
    return *this;
}