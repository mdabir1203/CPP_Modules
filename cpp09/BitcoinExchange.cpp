/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:00:17 by mabbas            #+#    #+#             */
/*   Updated: 2023/10/23 02:51:01 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){};

BitcoinExchange::BitcoinExchange(const std::string& dbFileName)
{
    std::ifstream dbFile(dbFileName);
    std::string line, date;
    float rate;

    while (getline(dbFile, line))
    {
        std::istringstream ss(line);
        getline(ss, date, '|');
        ss >> rate;
        exchangeRates[date] = rate;
    }
    dbFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copyBTC)
{
    exchangeRates = copyBTC.exchangeRates; 
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copyBTC)
{
    if (this != &copyBTC){
        exchangeRates = copyBTC.exchangeRates;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    
}

static bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static int getDaysInMonth(int month, int year) {
    static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month];
}

// Validation check ->  length, hyphen check, YMD extraction, Check Numeric, Check range(Y(>1900), M(1 - 12), D(with / wout leap year))
bool BitcoinExchange::validateDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-' )
    {
        throw WrongDateException();
    }
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    int year, month, day;

    try {
        year = std::stoi(yearStr);
        month = std::stoi(monthStr);
        day = std::stoi(dayStr);
    } catch (...){
        throw WrongDateException();
    }

    if (year < 1900 || year > 2100){
        throw WrongDateException();        
    }
    if (month < 1 || month > 12){
        throw WrongDateException();
    }

    if (day < 1 || day > getDaysInMonth(month, year))
        throw WrongDateException();

    return (true);
}

// -> invalid argument, out of range

bool BitcoinExchange::validateVal(const std::string &value, float &outVal)
{
    try{
        outVal = std::stof(value);
        if (outVal >= 0 && outVal <= 1000){
            return (true);
        } else{
            throw WrongValException();
        }
    } catch (const std::invalid_argument& ia){
        throw WrongValException();
    } catch (const std::out_of_range& oor){
        throw WrongValException();
    }
    return (false); // unnecessary and then completing the function
}

// ExchangeRates -> get lowerbounds, checkDatefound, closest lower Date(if at begining don't decrease)
// Return (exchangeRate for foundDate / closest lower date)
// -> lower_bound -> find the date / next higher date
// -> If (dateNotFound and not start -> decrement)
// If no lowerDate -> return defaultVal / exception
// retunr (exchangeRate-> foundDate / closestLowerDate)

float BitcoinExchange::getExchangeRate(const std::string &date)
{
    
    std::map<std::string, float>::iterator it = exchangeRates.lower_bound(date);
    
    if (it == exchangeRates.end() || it->first != date){
        if (it == exchangeRates.begin()){
            return (0.0f);
        }
        --it;
    }
    return (it->second);
}


// -> reads from input
// -> parses each line -> extract date and val
// -> validates extracted data
// -> Retrieves exchange rate for date 
// -> If any data invalid ->  throw exception
void BitcoinExchange::processCSV(const std::string &inFile)
{
    std::ifstream inputFilename(inFile);
    std::string line, date, valueStr;
    float value;

    while (getline(inputFilename, line)){
        std::istringstream ss(line);
        getline(ss, date, '|');
        getline(ss, valueStr);

        if (validateDate(date) && validateVal(valueStr, value)){
            float rate = getExchangeRate(date);
            std::cout << "Value on " << date << ": " << value * rate << std::endl;
        } else {
            throw WrongInputException();
        }
    }
    inputFilename.close(); // call the close on a stream object
}