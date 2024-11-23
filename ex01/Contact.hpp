/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:53:37 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/23 18:25:20 by mbirou           ###   ########.fr       */
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

		void		set_contact(std::string first_name, std::string last_name,
						std::string nickname, std::string phone_num, std::string secret);
		std::string	show_first_name(void);
		std::string	show_last_name(void);
		std::string	show_nickname(void);
		std::string	show_phone_num(void);
		std::string	show_secret(void);

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_num;
		std::string	secret;
};

#endif
