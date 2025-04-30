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

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void): i(0) {
    return;
}

PhoneBook::~PhoneBook(void) {
    return;
}

bool PhoneBook::ft_empty(const std::string& prompt, std::string& dest) {
	std::cout << prompt <<":";
	std::getline(std::cin, dest);
	if (std::cin.eof()) {std::cout << std::endl;}
	if (dest.empty()) {// && !std::cin.eof()
		std::cout << ".." << prompt << " cannot be empty!" << std::endl;}
	return dest.empty();
}

//contacts est un attribut membre de PhoneBook donc je peux y acceder
//directement depuis une fonction sans le mettre en parametre
void PhoneBook::ft_add(void) {
	if (ft_empty("First name", this->new_contact.f_name)) return;
	if (ft_empty("Last name", this->new_contact.l_name)) return;
	if (ft_empty("Nickname", this->new_contact.n_name)) return;
	if (ft_empty("Phone number", this->new_contact.number)) return;
	if (ft_empty("Darkest secret", this->new_contact.secret)) return;

	//Gerer les espaces avant et apres ?
	this->contacts[this->i] = this->new_contact;
	this->i = (this->i + 1) % 8;
	return ;
}


void PhoneBook::ft_search(void)  {
    return;
}