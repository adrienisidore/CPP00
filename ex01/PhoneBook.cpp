/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:00:53 by aisidore          #+#    #+#             */
/*   Updated: 2025/06/20 11:20:12 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(int pi): i(pi)
{
    return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "..Exiting program." << std::endl;
    return;
}

bool PhoneBook::ft_save(const std::string prompt)
{
	std::string	value;
	size_t		start;
	size_t		end;

	std::cout << prompt <<":";
	std::getline(std::cin, value);
	if (std::cin.eof())
		std::cout << std::endl;
	if (value.empty() || value.find_first_not_of(" \t") == std::string::npos)
	{
		if (!std::cin.eof())
			std::cout << ".." << prompt << " cannot be empty!" << std::endl;
		return (true);
	}
	start = value.find_first_not_of(" \t");
	end = value.find_last_not_of(" \t");
	value = value.substr(start, end - start + 1);
	//optionnel
	//std::string	alpha;
	//alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//if (prompt != "Phone number" && value.find_first_not_of(alpha) != std::string::npos)
	//{	
	//	std::cout << "Enter a valid " << prompt << " !" << std::endl;
	//	return (true);
	//}
	//else if (prompt == "Phone number" && value.find_first_not_of("0123456789") != std::string::npos)
	//{
	//	std::cout << "..Phone number can only contain numbers!" << std::endl;
	//	return (true);
	//}
	this->new_contact.ft_set(prompt, value);
	return (false);
}

void PhoneBook::ft_add(void)
{
	if (ft_save("First name")) return;
	if (ft_save("Last name")) return;
	if (ft_save("Nickname")) return;
	if (ft_save("Phone number")) return;
	if (ft_save("Darkest secret")) return;
	this->i = this->i % 8;
	this->contacts[this->i] = this->new_contact;
	++(this->i);
	return ;
}

std::string PhoneBook::ft_trunc(const std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	PhoneBook::ft_printab(void) const
{
	std::cout << std::setw(10) << "Index" << "|"
	<< std::setw(10) << "First Name" << "|"
	<< std::setw(10) << "Last Name" << "|"
	<< std::setw(10) << "Nickname" << "|";
}

void	PhoneBook::ft_print(const size_t idx)
{

	if (this->contacts[idx - 1].ft_get("First Name").empty())
	{
		std::cout << "Contact " << idx << " is empty !" << std::endl;
		return ;
	}
	this->ft_printab();
	std::cout << std::setw(10) << ft_trunc("Phone number") << "|"
	<< std::setw(10) << ft_trunc("Darkest secret") << "|"
	<< std::endl
	<< std::setw(10) << idx << "|"
	<< std::setw(10) << ft_trunc(this->contacts[idx - 1].ft_get("First Name")) << "|"
	<< std::setw(10) << ft_trunc(this->contacts[idx - 1].ft_get("Last Name")) << "|"
	<< std::setw(10) << ft_trunc(this->contacts[idx - 1].ft_get("Nickname")) << "|"
	<< std::setw(10) << ft_trunc(this->contacts[idx - 1].ft_get("Phone number")) << "|"
	<< std::setw(10) << ft_trunc(this->contacts[idx - 1].ft_get("Darkest secret")) << "|" << std::endl;
}

void PhoneBook::ft_search(void)
{
	int			j;
	std::string idx;


	if (this->contacts[0].ft_get("First Name").empty())
	{
		std::cout << "The Phonebook is empty !" << std::endl;
		return ;
	}
	this->ft_printab();
	j = 0;
	while (j < 8)
	{
		//Pour ne pas afficher les champs de contact vides
		if (this->contacts[j].ft_get("First Name").empty())
			j++;
		else
		{
			std::cout << std::endl << std::setw(10) << j + 1 << "|"
		          << std::setw(10) << ft_trunc(this->contacts[j].ft_get("First Name")) << "|"
		          << std::setw(10) << ft_trunc(this->contacts[j].ft_get("Last Name")) << "|"
		          << std::setw(10) << ft_trunc(this->contacts[j].ft_get("Nickname")) << "|";
			j++;
		}
	}
	std::cout << std::endl << "Index:";
	std::getline(std::cin, idx);
	if (idx.size() == 1 && idx[0] > '0' && idx[0] < '9')
		return (ft_print(static_cast<size_t>(idx[0] - '0')));
	if (!std::cin.eof())
		std::cout << "..Invalid index !" << std::endl;
	return ;
}