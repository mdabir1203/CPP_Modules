/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:37:53 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/28 11:08:06 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <string>

/*
*Here we chose to use const std::string in the getType()
 function avoid copy of type attribute and make it less expensive

*/

class Weapon
{
    private:
        std::string type;

    public:
        Weapon(const std::string& weaponType);
        const std::string getType() const;
        void setType(const std::string& chosenType) ;
};



#endif
    