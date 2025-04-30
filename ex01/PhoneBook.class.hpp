/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:45:57 by aisidore          #+#    #+#             */
/*   Updated: 2025/04/29 18:51:57 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

class PhoneBook {
public:
    PhoneBook(void);
	~PhoneBook(void);
	
	void	ft_add(void);
	void	ft_search(void);
	
private:
	Contact 	contacts[8];
	Contact		new_contact;
	int			i;
	bool		ft_empty(const std::string& prompt, std::string& dest);
	std::string	ft_trunc(const std::string& str);
	void		ft_printab(void);
	void		ft_print(const size_t idx);

};

#endif
