/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:51:18 by mabbas            #+#    #+#             */
/*   Updated: 2023/10/29 16:38:26 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string str) {
	this->data = str;
	add_data(str);
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & copy) {
	if (this != &copy) {
		this->data = copy.data;
	}
	return *this;
}

// Time validation -> length , format, hyphen check, parse to y,m,d and check, 
int	BitcoinExchange::check_time(std::string time) {
	int count;

	count = 0;
	for (size_t i = 0; i < time.length(); i++) {
		if (time[i] == '-') {
			count++;
		}
	}
	if (count != 2) {
		std::cout << error_msg[INVALID_TIME] << std::endl;
		return 0;
	}
	int y,m,d;
	if (sscanf(time.c_str(), "%d-%d-%d", &y, &m, &d) != 3) {
		std::cout << error_msg[INVALID_TIME] << std::endl;
		return 0;
	}
	if (y < 0 || y > 9999 || m < 0 || m > 12 || d < 0 || d > 31) {
		std::cout << error_msg[INVALID_TIME] << std::endl;
		return 0;
	}
	return 1;
}

// Price validation -> length, format,
// ->check if positive, 
// -> check if number,
// -> check if too large, 
// -> check if its digit or not

int	BitcoinExchange::check_price(std::string price)
{
	int count = 0;
	size_t i = 0;
	
	while (i++ < price.length())
	{
		if (price[i] == '.')
			count++;
	}
	if (count > 1) {
		std::cout << error_msg[INVALID_PRICE] << std::endl;
		return 0;
	}
	if (price[0] == '-')
	{
		std::cout << error_msg[NOT_POSITIVE_NUM] << std::endl;
		return 0;
	}
	//std::cout << price << std::endl;
	size_t j = 0;
	while (j++ < price.length())
	{
		if (price[i] == '.')
		{
			if (isdigit(price[i]) == 0)
			{
				std::cout << error_msg[NOT_A_NUMBER] << std::endl;
				return 0;
			}
		}
	}
	return (1);

}

// -> Input str correct format
// -> Extract date and price 
//-> check if valid 
//-> read price data from file 
//-> calculate val and print res

void BitcoinExchange::add_data(std::string data) {
	int count = 0;
	float _value;
	std::string _time;

	for (size_t i = 0; i < data.length(); i++) {
		if (data[i] == '|') {
			count++;
		}
	}
	if (count != 1) {
		std::cout << error_msg[BAD_INPUT] << data << std::endl;
		return ;
	}
	_time = data.substr(0,data.find('|') - 1);
	//std::cout << _time << std::endl;
	if (check_time(_time) == 0) {
		return ;
	}
	if (check_price(data.substr(data.find('|') + 2, data.length())) == 0) {
		return ;
	}
	_value = atof(data.substr(data.find('|') + 2, data.length()).c_str());
	if (_value > 1000) {
		std::cout << error_msg[TOO_LARGE_NUM] << std::endl;
		return ;
	}
	this->time = _time;
	this->value = _value;
	// Process csv to get price 
	std::ifstream f("data.csv");
	if (!f.is_open())
	{
		std::cout << error_msg[FILE_NOT_FOUND] << std::endl;
		return ;
	}
	std::string line;
	//  initialize , read file , compare time-> update price, price not found->error , Display final value
	float price = -1;
	while(getline(f, line))
	{
		if (strcmp(_time.c_str(), line.substr(0, line.find(',')).c_str()) == 0)
		{

			price = atof(line.substr(line.find(',') + 1, line.size() - 1).c_str());
		}
		else if (strcmp(_time.c_str(), line.substr(0, line.find(',')).c_str()) > 0)
		{
			price = atof(line.substr(line.find(',') + 1, line.size() - 1).c_str());
		}
	}
	if (price == -1)
	{
		std::cout << error_msg[PRICE_NOT_EXIST] << std::endl;
		return ;
	}
	std::cout << this->time << " => " << this->value << " = " << ((float)(price * value)) << std::endl;
}