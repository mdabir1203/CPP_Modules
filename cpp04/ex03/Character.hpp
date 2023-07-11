/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:23:00 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 02:28:55 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{

private:
    std::string name;
    AMateria    *inventory[4];

public:
    Character(std::string const &name);
    Character(Character const &src);
    ~Character();

    Character&          operator=(Character const &rhs);

    std::string const&  getName() const;
    void                equip(AMateria* m);
    void                unequip(int idx);
    void                use(int idx, ICharacter& target);
};

#endif // CHARACTER_HPP