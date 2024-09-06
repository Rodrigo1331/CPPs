/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:27:34 by rcruz-an          #+#    #+#             */
/*   Updated: 2024/09/05 18:12:21 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0){
    _nbAccounts += 1;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account( void ){
    _nbAccounts -= 1;
    _totalAmount -= _amount;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void){
    return 	_nbAccounts;
}

int Account::getTotalAmount(void){
    return _totalAmount;
}

int Account::getNbDeposits(void){
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void){
    return _totalNbWithdrawals;
}

void Account::_displayTimestamp(void){
    time_t currentTime = time(0);
    struct tm *localTime = localtime(&currentTime);

    /* [YYYYMMDD_HHMMSS] */
    std::cout << "[" << (localTime->tm_year + 1900);
    /* std::cout << std::setw(2) << (localTime->tm_mon + 1); */
    std::cout << std::setfill('0') << std::setw(2) << (localTime->tm_mon + 1);
    std::cout << std::setfill('0') << std::setw(2) << localTime->tm_mday << "_";
    std::cout << std::setfill('0') << std::setw(2) << localTime->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << localTime->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << localTime->tm_sec << "]";
}

void Account::makeDeposit (int deposit){
    _displayTimestamp();
    _nbDeposits += 1;

    std::cout << " index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";
    _amount += deposit;
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;

    _totalNbDeposits += 1;
    _totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal){
    _displayTimestamp();
    if (withdrawal > _amount){
        std::cout << " index:" << _accountIndex << ";";
        std::cout << "p_amount:" << _amount << ";";
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
    _nbWithdrawals += 1;
    
    std::cout << " index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "withdrawal:" << withdrawal << ";";
    _amount -= withdrawal;
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_withdrawls:" << _nbWithdrawals << std::endl;

    _totalNbWithdrawals += 1;
    _totalAmount -= withdrawal;
    return true;
}

int Account::checkAmount(void) const{
    return _totalAmount;
}

void Account::displayAccountsInfos(void){
    _displayTimestamp();

    std::cout << " accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus(void) const{
    _displayTimestamp();

    std::cout << " index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits" << _nbDeposits << ";";
    std::cout << "withdraws:" << _nbWithdrawals << std::endl;

}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;