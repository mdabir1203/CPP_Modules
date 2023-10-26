#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>

#define errorMessage "Error: bad input => "

class BitcoinExchange {
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& to_copy);
        BitcoinExchange& operator=(const BitcoinExchange& to_copy);
        ~BitcoinExchange(void);

        void readInternalDataBase(std::ifstream& internal_db);

        float getRateFromDataBase(const std::string& date);

        bool validateDateFormat(const std::string &date);
        bool isValidDate(const std::string& date);
        bool validateRate(const std::string& rate);

    private:
        std::map<std::string, float> dataBase;
};

#endif 