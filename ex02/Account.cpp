/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:03:53 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/26 19:43:41 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	std::time_t	time;
	char		timestring[] = "[yyyymmdd_hhmmss]";
	std::time(&time);
	std::strftime(timestring, 17, "[%Y%m%d_%H%M%S]", std::gmtime(&time));
	std::cout << timestring;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout	<< " accounts:" << Account::getNbAccounts()
				<< ";total:" << Account::getTotalAmount()
				<< ";deposits:" << Account::getNbDeposits()
				<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = Account::getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts ++;
	Account::_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" << this->checkAmount()
				<< ";created" << std::endl;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout 	<< " index:" << this->_accountIndex
				<< ";amount:" << this->checkAmount()
				<< ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits ++;
	this->_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";p_amount:" << this->checkAmount()
				<< ";deposit:" << deposit
				<< ";amount:" << this->checkAmount() + deposit
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
	this->_amount = this->checkAmount() + deposit;
	this->_totalAmount += deposit;
	this->_totalNbDeposits ++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->checkAmount() - withdrawal < 0)
		return (false);
	this->_nbWithdrawals ++;
	this->_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";p_amount:" << this->checkAmount()
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << this->checkAmount() - withdrawal
				<< ";nb_withdrawals:" << this->_nbDeposits
				<< std::endl;
	this->_amount = this->checkAmount() - withdrawal;
	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals ++;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex << ";amount:" << this->checkAmount()
				<< ";deposits:" << this->_nbDeposits << ";withdrawals:"
				<< this->_nbWithdrawals << std::endl;
}
