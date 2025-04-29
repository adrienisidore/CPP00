/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:58:05 by aisidore          #+#    #+#             */
/*   Updated: 2025/04/29 19:00:48 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "PhoneBook.class.hpp"

int main() {
    
	PhoneBook phonebook; // Appel au constructeur
	std::string buff;//Proteger buff
	
	while (1)
	{
		std::cout << "Phonebook:";
		if (!std::getline(std::cin, buff)) {
			//std::getline(std::cin >> std::ws, buff); supprime espaces avant saisie
			std::cout << std::endl << "..Exiting program." << std::endl;
			break;
		}
		// std::getline(std::cin, buff);
		// char buff[256];
		// std::cin.getline(buff, 256); mais ca retire pas espaces blancs et c proche du C
		// std::strcmp(buff, "EXIT")
		if (buff == "ADD")
		{
			std::cout << buff << std::endl;
			phonebook.ft_add();
		}
		else if (buff == "SEARCH")
		{
			std::cout << buff << std::endl;
			phonebook.ft_search();
		}
		else if (std::cin.eof() || buff == "EXIT")
		{//CTRL+D. L'ajouter a d'autres endroits ?
            // std::cin.clear();//utile si je veux effacer le flag d'erreur (par ex ignorer une mauvaise entree utilisateur)
            std::cout << std::endl << "..Exiting program." << std::endl;
            break ;
        }
	}

    return (0);//le destructeur est appele. A chaque fin de fonction
	//que ce soit un main ou autre
}

