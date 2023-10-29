/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:51:05 by mabbas            #+#    #+#             */
/*   Updated: 2023/10/29 16:27:33 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>

enum ErrorCode {
    NO_ERROR,
    INVALID_TIME,
    INVALID_PRICE,
    NOT_POSITIVE_NUM,
    NOT_A_NUMBER,
    BAD_INPUT,
    TOO_LARGE_NUM,
    FILE_NOT_FOUND,
    PRICE_NOT_EXIST,
    NOT_OPEN_FILE
};

const std::string error_msg[] = {
    "No error",
    "Error: Invalid time",
    "Error: Invalid price",
    "Error: Not a positive number",
    "Error: Not a number",
    "Error: bad input => ",
    "Error: too large a number",
    "Error: File not found",
    "Error: Price not exist",
    "Error: could not open file."
};

class BitcoinExchange {
    private :
        std::string data;
        int value;
        std::string time;
    public :
        BitcoinExchange();
        BitcoinExchange(std::string str);
        BitcoinExchange(BitcoinExchange const & src);
        ~BitcoinExchange();
        BitcoinExchange & operator=(BitcoinExchange const & copy);
        void add_data(std::string data);
        std::string get_data();
        void print_data();
        int check_data(std::string data);
        int check_time(std::string time);
        int check_price(std::string price);
        float get_price(const std::string& time);
        bool validate_input(const std::string& data); 
        
};
#endif