/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:45:57 by aisidore          #+#    #+#             */
/*   Updated: 2025/04/28 19:03:06 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PhoneBook.hpp
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];

public:
    PhoneBook();
};

#endif
