/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:53:37 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/25 12:04:21 by mbirou           ###   ########.fr       */
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
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		std::string	get_phone_num(void);
		std::string	get_secret(void);

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_num;
		std::string	secret;
};

#endif
