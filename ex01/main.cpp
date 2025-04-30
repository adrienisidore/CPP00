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

//Ctrl+D = EOF : on arrete de lire 5desactive std//cin) 
//et .eof() == true. Ce n'est pas pareil qu'avoir une
//chaine vide. Chaine vide est valide comme string, et on pourra faire appel à getline
//plus tard car le fichier temporaire est encore ouvert.

//if (std::cin.eof()) {std::cin.clear();}//le buffer std::cin de nouveau utilisable
//cependant std::cin reste vide (plus rien à lire car std::cin definitivement ferme)
//donc lorsque je fais getline dans le main()
//ca enclenche de nouveau EOF ce qui me fait sortir du programme (2eme else if)
//Ctrl+D = le flux est terminé pour toute la durée du programme

int main() {
    
	PhoneBook	phonebook; // Appel au constructeur
	std::string buff;//Proteger buff ou on laisse C++ gerer sa taille trop grande ?
	
	while (1)
	{		
		std::cout << "Phonebook:"; std::getline(std::cin, buff);
		if (buff == "ADD")
			phonebook.ft_add();
		else if (buff == "SEARCH")
			phonebook.ft_search();
		if (std::cin.eof() || buff == "EXIT")
            std::cout << "..Exiting program." << std::endl; break;
	}
    return (0);//le destructeur est appele. A chaque fin de fonction
	//que ce soit un main ou autre
}

