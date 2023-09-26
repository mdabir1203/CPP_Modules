/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:12:04 by mabbas            #+#    #+#             */
/*   Updated: 2023/09/19 23:29:37 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Colors.hpp"

int main()
{
	Serializer serial;
    Data	data = {.val = 4242, .str = "My attention sucks!"};
	uintptr_t	serializedPointerAsInt = serial.serialize(&data);
	Data*		deserializedPointer = serial.deserialize(serializedPointerAsInt);

	if (deserializedPointer == &data)
		std::cout << BRIGHT_GREEN "Successful serialization and deserialization." RESET
			<< std::endl;
	else
		std::cout << BG_RED "Failed serialization and deserialization: " RESET
			<< std::endl << std::endl;
	std::cout <<  "Original " <<  BG_PURPLE << data << BG_RED << std::endl;
	std::cout << "Pointer to data structure serialized as int: "
		<< serializedPointerAsInt << std::endl;
	std::cout << "Deserialized " << *deserializedPointer << std::endl;
	return (0);
}
