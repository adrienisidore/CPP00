/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:00:53 by aisidore          #+#    #+#             */
/*   Updated: 2025/06/18 15:24:05 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(int pi): i(pi) {
    return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "..Exiting program." << std::endl;
    return;
}

bool PhoneBook::ft_empty(const std::string& prompt, std::string& dest) {
	size_t start;
	size_t end;

	std::cout << prompt <<":";
	std::getline(std::cin, dest);
	if (std::cin.eof()) {std::cout << std::endl;}
	//si find_first_not_of va jusqu'à la taille maximale d'une string (npos),
	//c'est qu'il n'a pas trouvé autre chose que des espaces et des tabultations 
	if (dest.empty() || dest.find_first_not_of(" \t") == std::string::npos)
	{
		if (!std::cin.eof())
			std::cout << ".." << prompt << " cannot be empty!" << std::endl;
		return (true);
	}
	//On reformate new_contact pour retirer les espaces avant et après
	start = dest.find_first_not_of(" \t");
	end = dest.find_last_not_of(" \t");
	dest = dest.substr(start, end - start + 1);
	return (false);//booléen vrai si empty, faux sinon
}

//contacts est un attribut membre de PhoneBook donc je peux y acceder
//directement depuis une fonction sans le mettre en parametre
void PhoneBook::ft_add(void) {
	if (ft_empty("First name", this->new_contact.f_name)) return;
	if (ft_empty("Last name", this->new_contact.l_name)) return;
	if (ft_empty("Nickname", this->new_contact.n_name)) return;
	if (ft_empty("Phone number", this->new_contact.number)) return;
	if (this->new_contact.number.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "..Phone number can only contain numbers!" << std::endl;
		return;
	}
	if (ft_empty("Darkest secret", this->new_contact.secret)) return;
	this->contacts[this->i] = this->new_contact;
	this->i = (this->i + 1) % 8;
	return;
}


std::string PhoneBook::ft_trunc(const std::string& str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	PhoneBook::ft_printab(void) const {
	std::cout << std::setw(10) << "Index" << "|"
	<< std::setw(10) << "First Name" << "|"
	<< std::setw(10) << "Last Name" << "|"
	<< std::setw(10) << "Nickname" << "|";
}

void	PhoneBook::ft_print(const size_t idx) {

	this->ft_printab(); 
	std::cout << std::setw(10) << ft_trunc("Phone number") << "|"
	<< std::setw(10) << ft_trunc("Darkest secret") << "|"
	<< std::endl
	<< std::setw(10) << idx << "|"
	<< std::setw(10) << ft_trunc(this->contacts[idx].f_name) << "|"
	<< std::setw(10) << ft_trunc(this->contacts[idx].l_name) << "|"
	<< std::setw(10) << ft_trunc(this->contacts[idx].n_name) << "|"
	<< std::setw(10) << ft_trunc(this->contacts[idx].number) << "|"
	<< std::setw(10) << ft_trunc(this->contacts[idx].secret) << "|" << std::endl;
}

void PhoneBook::ft_search(void) {
	std::string idx;
	size_t		index;

	this->ft_printab();
	for (int j = 0; j < 8; ++j)
	{
		if (this->contacts[j].f_name.empty())
			continue; // Ignore les emplacements non utilisés
		std::cout << std::endl << std::setw(10) << j << "|"
		          << std::setw(10) << ft_trunc(this->contacts[j].f_name) << "|"
		          << std::setw(10) << ft_trunc(this->contacts[j].l_name) << "|"
		          << std::setw(10) << ft_trunc(this->contacts[j].n_name) << "|";
	}
	std::cout << std::endl << "Index:";
	std::getline(std::cin, idx);
	if (idx.size() != 1 || idx[0] < '0' || idx[0] > '7')
		std::cout << "..Invalid index!" << std::endl;
	else 
	{
		index = static_cast<size_t>(idx[0] - '0');
		ft_print(index);
	}
	return ;
}