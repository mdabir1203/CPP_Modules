/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:47:35 by mabbas            #+#    #+#             */
/*   Updated: 2023/09/19 23:24:41 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>


struct Data
{
    unsigned int    val;
    std::string     str;
};

class Serializer 
{
    public:
        uintptr_t serialize(Data* ptr);
        Data*    deserialize(uintptr_t raw);
        
};

std::ostream& operator<<(std::ostream& stream, const Data &obj);


#endif