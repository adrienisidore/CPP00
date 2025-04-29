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

//contacts est un attribut membre de PhoneBook donc je peux y acceder
//directement depuis une fonction sans le mettre en parametre
void PhoneBook::ft_add(void)  {
	std::cout << "First name:";
	if (!std::getline(std::cin >> std::ws, this->contacts[i].f_name)) {
		return;
	}//faire pareil pour tous les autres
	std::cout << "Last name:";
	std::getline(std::cin >> std::ws, this->contacts[i].l_name);
	std::cout << "Nickname:";
	std::getline(std::cin >> std::ws, this->contacts[i].n_name);
	std::cout << "Phone number:";
	std::getline(std::cin >> std::ws, this->contacts[i].number);
	std::cout << "Darkest secret:";
	std::getline(std::cin >> std::ws, this->contacts[i].secret);
	i = (i + 1) % 8;
    return;
}

void PhoneBook::ft_search(void)  {
    return;
}