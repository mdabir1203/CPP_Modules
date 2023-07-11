/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:19:11 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 01:48:55 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
    std::cout << this->type << " constructor is summoned" << std::endl;
    try {
        this->brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Memory Allocation is failed : " << e.what() << std::endl;
    }
}

Cat::~Cat( void )
{
    std::cout << this->type << " destructor is summoned" << std::endl;
    delete  this->brain;
}

void    Cat::makeSound( void ) const
{
    std::cout << "Meow!" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src)
{
    *this = src;
}

Cat& Cat::operator=(const Cat& src)
{
    std::cout << "<Cat.cpp:32> Cat copy is summoned." << std::endl;
    if (this != &src)
    {
        this->type = src.type;
        this->brain = new Brain( *src.brain );
    }
    return *this;
}