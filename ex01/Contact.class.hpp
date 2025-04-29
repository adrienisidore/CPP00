/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:46:32 by aisidore          #+#    #+#             */
/*   Updated: 2025/04/29 16:33:56 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Contact.hpp
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>//for what ?
#include <string>//for what ?

class Contact {
public:
    // Constructeur
    Contact(void);
	~Contact(void);

    // Méthode pour afficher un message
    void display() const;
};

#endif
