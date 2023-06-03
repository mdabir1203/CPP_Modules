/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:49:25 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/04 00:41:29 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Account.hpp"
#include <iostream>
#include <ctime>

/** initializing the static member var*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/** Implementation of s.mem.var*/

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

/** construction of constructor and destructor **/
Account::Account(int initial_deposit): _amount(initial_deposit)
{
    _accountIndex = _nbAccounts;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
    _totalAmount += initial_deposit;
    _nbAccounts++;
}

Account::~Account()
{
    _nbAccounts--;
    _totalAmount -= _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount" << _amount
              << ";deposit" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";withdrawal:";
    if (_amount >= withdrawal)
    {
        _amount = withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << withdrawal
                  << ";amount:" << _amount
                  << ";nb_withdrawals: " << _nbWithdrawals << std::endl;
        return true;
    }
    else
    {
        std::cout << "refused" << std::endl;
        return false;
    }
}


int Account::checkAmount() const
{
    return _amount;
}

void Account::_displayTimestamp()
{
    std::time_t now = std::time(nullptr);
    std::tm* current_time = std::localtime(&now);
    char buffer[80];

    std::strftime(buffer, sizeof(buffer), "[%a %b %d %H:%M:%S %Y]", current_time);
    std::cout << buffer ;

    
}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << "\n";
}
