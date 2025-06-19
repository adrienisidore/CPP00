/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:00:43 by aisidore          #+#    #+#             */
/*   Updated: 2025/04/29 17:07:11 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	//Initialiser toutes les valeurs vides d'un contact
    return;
}

Contact::~Contact(void) {
    return;
}

//Juste pour l'affichage dans SEARCH, 
std::string Contact::ft_get(const std::string field) const {
    if (field == "First Name")
        return (this->f_name);
    else if (field == "Last Name")
        return (this->l_name);
    else if (field == "Nickname")
        return (this->n_name);
    else if (field == "Phone number")
        return (this->number);
    else if (field == "Darkest secret")
        return (this->secret);
    else
        return "Unknown field";
}

void Contact::ft_set(const std::string field, const std::string value)
{
    if (field == "First Name")
        this->f_name = value;
    else if (field == "Last Name")
        this->l_name = value;
    else if (field == "Nickname")
        this->n_name = value;
    else if (field == "Phone number")
        this->number = value;
    else if (field == "Darkest secret")
        this->secret = value;
}