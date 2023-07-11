/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:21:08 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 02:16:16 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
protected:
    std::string type;

public:
    AAnimal( void );
    AAnimal( std::string type );
    virtual ~AAnimal( void );

    AAnimal(const AAnimal& src);
    AAnimal& operator=(const AAnimal& rhs);

    virtual void    makeSound( void ) const = 0;;
    std::string     getType( void ) const; 
};

#endif // AANIMAL_HPP