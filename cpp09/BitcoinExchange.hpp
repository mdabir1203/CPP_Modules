/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:35:00 by mabbas            #+#    #+#             */
/*   Updated: 2023/10/23 02:51:36 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <map>
#include <string>

class BitcoinExchange
{
    public:

        
        BitcoinExchange();
        BitcoinExchange(const std::string &dbFilename);
        BitcoinExchange(BitcoinExchange const &copyBTC);
        ~BitcoinExchange();
        
        BitcoinExchange &operator=(BitcoinExchange const &copyBTC);

        void processCSV(std::string const &inFile);
//TODO: parsing, wrong input, wrongNumber, wrongData
        class CsvParsingException: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("BitcoinExchange::exception: parsing file error");
                }
        };

        class WrongInputException: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Error: wrong input");
                }
        };
        
        class WrongValException: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Error: you are putting wrong values braah! ");
                }
        };

        class WrongDateException: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Error: check the calendar style in subject");
                }
        };
    
    private:
        std::map<std::string, float> exchangeRates;
        bool validateDate(const std::string &date);
        bool validateVal(const std::string &val, float &outVal);
        float getExchangeRate(const std::string &date);    
    
};


#endif