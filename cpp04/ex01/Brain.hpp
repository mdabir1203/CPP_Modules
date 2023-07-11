/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:19:02 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 01:19:04 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
    std::string _ideas[100];

public:
    Brain( void );
    ~Brain( void );
    Brain( const Brain& src );
    Brain& operator=( const Brain& rhs );
};
 
#endif // BRAIN_HPP