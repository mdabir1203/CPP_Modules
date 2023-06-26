/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:17:03 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/23 12:17:03 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


class Harl
{
    
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public:
        void complain(char cases);
};