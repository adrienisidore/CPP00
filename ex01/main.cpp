/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:58:05 by aisidore          #+#    #+#             */
/*   Updated: 2025/06/18 15:14:33 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//Voir commentaire TODO pour utilisation cin,eof()

int main(void) {
    
	PhoneBook	phonebook(0); // Appel au constructeur
	std::string buff;
	
	while (1)
	{		
		std::cout << "Phonebook:"; std::getline(std::cin, buff);
		if (buff == "ADD")
			phonebook.ft_add();
		else if (buff == "SEARCH")
			phonebook.ft_search();
		if (std::cin.eof() || buff == "EXIT")
		{
			if (std::cin.eof())
				std::cout << "..EOF detected";	
			break;
		}
	}
    return (0);//le destructeur est appele. A chaque fin de fonction
	//que ce soit un main ou autre
}

