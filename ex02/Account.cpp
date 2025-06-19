/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:29:26 by aisidore          #+#    #+#             */
/*   Updated: 2025/06/18 15:10:00 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Account.hpp"
# include <iostream>
# include <ctime>//timestamp
# include <iomanip> // pour setw

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	Account::_nbAccounts++; // Je crée un compte supplémentaire
	this->_accountIndex = Account::_nbAccounts - 1; // J'attribue un index au compte créé
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	Account::_totalAmount += this->_amount;
}

Account::~Account(void) 
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts); // Variable statique → pas de this->
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount); // Idem
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	          << ";amount:" << this->_amount
	          << ";deposits:" << this->_nbDeposits
	          << ";withdrawals:" << this->_nbWithdrawals
	          << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	current_time;
	std::tm*	local_time;

	current_time = std::time(NULL);
	local_time = std::localtime(&current_time);
	std::cout << '[' << std::setfill('0') << std::setw(4) << 1900 + local_time->tm_year
			  << std::setw(2) << local_time->tm_mon + 1
			  << std::setw(2) << local_time->tm_mday << '_'
			  << std::setw(2) << local_time->tm_hour
			  << std::setw(2) << local_time->tm_min
			  << std::setw(2) << local_time->tm_sec << "] ";
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();				
	std::cout << "accounts:" << Account::_nbAccounts
	          << ";total:" << Account::_totalAmount
	          << ";deposits:" << Account::_totalNbDeposits
	          << ";withdrawals:" << Account::_totalNbWithdrawals
	          << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	          << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	std::cout << ";deposit:" << deposit
	          << ";amount:" << this->_amount
	          << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (this->_amount >= withdrawal)
	{
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout << withdrawal << ";amount:" << this->_amount
		          << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
}
	