/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:44:05 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/28 09:15:12 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon weapon;
    public:
        HumanA(const std::string& humanName, Weapon& weapon);
        void attack() const;
};


#endif
