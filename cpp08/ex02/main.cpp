/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:00:43 by mabbas            #+#    #+#             */
/*   Updated: 2023/10/21 11:50:56 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "includes/MutantStack.hpp"
#include <vector>


int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	MutantStack<int> ms;
	ms.push(1);
	ms.push(2);
	ms.push(3);
	ms.push(4);
	ms.push(5);

	MutantStack<int>::iterator begin = ms.begin();
	MutantStack<int>::iterator end = ms.end();

	std::cout << "stack = ";
	while (begin != end)
	{
		std::cout << *begin << " ";
		begin += 1;
	}

	std::cout << std::endl;
	return EXIT_SUCCESS;
}
