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

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
    PhoneBook(int pi);
	~PhoneBook(void);
	
	void	ft_add(void);
	void	ft_search(void);
	
private:
	Contact 	contacts[8];
	Contact		new_contact;
	int			i;
	//droit d'utiliser les références ?
	bool		ft_empty(const std::string& prompt, std::string& dest);
	std::string	ft_trunc(const std::string str);//&
	void		ft_printab(void) const;
	void		ft_print(const size_t idx);

};

#endif
