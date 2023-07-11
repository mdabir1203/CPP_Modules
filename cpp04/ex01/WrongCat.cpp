/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:20:47 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 01:57:34 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
    std::cout << this->type << " constructor is summoned" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << this->type << " destructor is summoned" << std::endl;
}

void    WrongCat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}