/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:39:05 by mabbas            #+#    #+#             */
/*   Updated: 2023/10/23 02:51:52 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac,char **av)
{
	if (ac != 2)
	{
		std::cout << "Enter your input file as argument\n";
		return (1);
	}
	std::string inFile(av[1]);

	BitcoinExchange priceRecord = BitcoinExchange();
	try
	{
		priceRecord.processCSV("data.csv");
	}
	catch(BitcoinExchange::CsvParsingException& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
	
}