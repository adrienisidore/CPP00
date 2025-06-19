/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:46:32 by aisidore          #+#    #+#             */
/*   Updated: 2025/04/29 18:16:25 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Contact.hpp
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip> // pour setw
#include <string>

class Contact {
public:
    Contact(void);
	~Contact(void);
	void		ft_set(const std::string field, const std::string value);
	std::string	ft_get(const std::string field) const;

	std::string f_name;
	std::string l_name;
	std::string n_name;
	std::string number;
	std::string secret;
};

#endif
