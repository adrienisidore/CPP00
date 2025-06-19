/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:29:26 by aisidore          #+#    #+#             */
/*   Updated: 2025/06/10 19:36:19 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//Quelle variable private dois-je initialiser
//J'hesite entre _amount et _totalAmount (qui est static)
Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_accountIndex = _nbAccounts - 1;//J'attribue un index au compte cree
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	//Variables statiques donc non-membres
	Account::_nbAccounts++;//Je cree un compte supplementaire
	Account::_totalAmount += _amount;//J'ajoute sa somme au global
	
}

Account::~Account(void) 
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}
	
static int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

static int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

static int	Account::getNbDeposits(void)
{
	return (_nbDeposits);
}

static int	Account::getNbWithdrawals(void)
{
	return (_nbWithdrawals);
}

static void	Account::displayAccountsInfos(void)
{
	//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0.. Pas sur pour deposits	
	_displayTimestamp();				
	std::cout << "accounts:" << _accountIndex << ";total:" << _totalAmount << ";deposits:" _nbDeposits << ";withdrawals:" << std::endl;
}


	