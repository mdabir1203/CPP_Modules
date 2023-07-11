/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:23:24 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 02:18:02 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{

    public:
        Ice();
        ~Ice();

        Ice(Ice const &);
        Ice& operator=(Ice const &);

        virtual AMateria*   clone() const;
        virtual void        use(ICharacter& target);
};

#endif // ICE_HPP