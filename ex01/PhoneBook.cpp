/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:00:53 by aisidore          #+#    #+#             */
/*   Updated: 2025/04/29 19:04:11 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//i n'est pas un attribut constant, mais c'est pas grave
PhoneBook::PhoneBook(int pi): i(pi) {
    return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "..Exiting program." << std::endl;
    return;
}

bool PhoneBook::ft_empty(const std::string& prompt, std::string& dest) {

	//ON FAIT UN FT_SET QUI RENVOIE L'ADRESSE DE CHAQUE ATTRIBUT
	std::cout << prompt <<":";
	std::getline(std::cin, dest);
	if (std::cin.eof())
		std::cout << std::endl;
	//si find_first_not_of va jusqu'à la taille maximale d'une string (npos),
	//c'est qu'il n'a pas trouvé autre chose que des espaces et des tabultations 
	if (dest.empty() || dest.find_first_not_of(" \t") == std::string::npos)
	{
		if (!std::cin.eof())
			std::cout << ".." << prompt << " cannot be empty!" << std::endl;
		return (true);
	}

	//On reformate new_contact pour retirer les espaces avant et après
	size_t	start = dest.find_first_not_of(" \t");
	size_t	end = dest.find_last_not_of(" \t");
	dest = dest.substr(start, end - start + 1);
	//à tester
	//std::string	alphabetic = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//if ((dest.find_first_of(" \t") != std::string::npos && prompt != "Darkest secret")
	//	|| (dest.find_first_not_of(alphabetic) != std::string::npos && prompt != "Phone number"))
	//{
	//	std::cout << std::endl << "Enter a valid " << prompt << " !" << std::endl;
	//	return (true);
	//}
	return (false);//booléen vrai si empty, faux sinon
}

//contacts est un attribut membre de PhoneBook donc je peux y acceder
//directement depuis une fonction sans le mettre en parametre
void PhoneBook::ft_add(void) {
	//au lieu de return on pourrait faire le récursivité pour éviter
	//de devoir retaper ADD dans le Terminal
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

	this->i = this->i % 8;
	this->contacts[this->i] = this->new_contact;
	++(this->i);
	return ;
}


std::string PhoneBook::ft_trunc(const std::string str) {
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

// Penser à ajouter le . en fin de troncage
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