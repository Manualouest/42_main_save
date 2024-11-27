/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:03:42 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/27 18:26:19 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		bool	add(void);
		bool	search(void);

	private:
		int		_oldest_index;
		int		_len;
		Contact	_contacts[8];

		std::string	_get_input(char *msg) const;
		std::string	_format_string(std::string text) const;
		void		_ShowContacts(void) const;
		void		_ShowContact(int index) const;
};

#endif
