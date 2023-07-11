/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:21:43 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 02:13:58 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal
{
private:
    Brain   *brain;

public:
    Dog(void);
    ~Dog(void);

    Dog(const Dog& src);
    Dog& operator=(const Dog& src);

    void   makeSound(void) const;
};

#endif // DOG_HPP