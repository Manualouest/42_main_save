/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:34:32 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/27 16:57:45 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
}


void		Contact::set_contact(std::string first_name, std::string last_name,
				std::string nickname, std::string phone_num, std::string secret)
{
	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nickname = nickname;
	this->_phone_num = phone_num;
	this->_secret = secret;
}

std::string	const Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string	const Contact::get_last_name(void) const
{
	return (this->_last_name);
}

std::string	const Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string	const Contact::get_phone_num(void) const
{
	return (this->_phone_num);
}

std::string	const Contact::get_secret(void) const
{
	return (this->_secret);
}

