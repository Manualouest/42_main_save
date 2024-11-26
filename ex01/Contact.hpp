/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:53:37 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/26 18:49:54 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void				set_contact(std::string first_name, std::string last_name,
								std::string nickname, std::string phone_num, std::string secret);
		std::string const	get_first_name(void) const;
		std::string const	get_last_name(void) const;
		std::string const	get_nickname(void) const;
		std::string const	get_phone_num(void) const;
		std::string const	get_secret(void) const;

	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_num;
		std::string	_secret;
};

#endif
