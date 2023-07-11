/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:19:27 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 01:59:20 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << this->type << " constructor is summoned" << std::endl;
    try {
        this->brain = new Brain();
    }
    catch (std::bad_alloc& e) {
        std::cout << "Memory Allocation is failed" << std::endl;
    }
}

Dog::~Dog(void)
{
    delete  this->brain;
    std::cout << this->type << " destructor is summoned" << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << "Woof!" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
    *this = src;
}

/**
 * Here it creates a new instance of the Brain class by copying the values from the object pointed to by src.brain.
 */
Dog& Dog::operator=(const Dog& src)
{
    std::cout << "Dog copy is summoned." << std::endl;
    if (this != &src)
    {
        this->type = src.type;
        this->brain = new Brain(*src.brain);
    }
    return *this;
}