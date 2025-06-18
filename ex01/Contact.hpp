/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:46:32 by aisidore          #+#    #+#             */
/*   Updated: 2025/06/18 17:39:44 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip> // pour setw
#include <string>

class Contact {
public:
    Contact(void);
	~Contact(void);
	// std::string *ft_get(std::string which) const;
private:
	std::string f_name;
	std::string l_name;
	std::string n_name;
	std::string number;
	std::string secret;
};

#endif

//Probleme de modulo. Deja l'indice doit commencer a 1 et pas 0 (je peux simplement afficher l'index et le chercher aussi a + 1).
//Ensuite au dela de 8 contacts je dois overright le suivant
