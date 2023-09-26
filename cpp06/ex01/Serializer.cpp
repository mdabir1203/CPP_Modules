/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:47:07 by mabbas            #+#    #+#             */
/*   Updated: 2023/09/19 23:25:37 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// UseCase: - For opaque data types -> In vendor API / external library
//          - Convert pointer to Hash code based on Address 
// - might lead to unsafe code -> 

uintptr_t Serializer::serialize(Data* ptr)
{
    return ((reinterpret_cast<uintptr_t>(ptr)));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *data_ptr;
    
    data_ptr = reinterpret_cast<Data *>(raw);
    return (data_ptr);
}

std::ostream& operator<<(std::ostream& stream, const Data &obj)
{
    stream << " Struct Data stored at address: [" << &obj << "]" 
           << "\n\t- val : " << obj.val
           << "\n\t- str :"  << obj.str << std::endl;
    return (stream);
}