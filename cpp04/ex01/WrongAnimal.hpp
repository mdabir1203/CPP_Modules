/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:20:41 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 01:57:18 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal(void);
    WrongAnimal(std::string type);
    ~WrongAnimal(void);

    WrongAnimal(const WrongAnimal& src);
    WrongAnimal& operator=(const WrongAnimal& rhs);

    void            makeSound(void) const;
    std::string     getType(void) const; 
};

#endif // WRONGANIMAL_HPP