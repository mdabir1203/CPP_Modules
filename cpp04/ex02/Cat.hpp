/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:21:31 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 02:13:26 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

class Cat : public AAnimal
{
private:
    Brain   *brain;

public:
    Cat(void);
    ~Cat(void);

    Cat(const Cat& src);
    Cat& operator=(const Cat& src);

    void   makeSound(void) const;
};

#endif // CAT_HPP