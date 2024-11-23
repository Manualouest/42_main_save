/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:34:32 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/23 19:54:43 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact  destructor called" << std::endl;
}


void		Contact::set_contact(std::string first_name, std::string last_name,
				std::string nickname, std::string phone_num, std::string secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_num = phone_num;
	this->secret = secret;
}

std::string	Contact::show_first_name(void)
{
	return (this->first_name);
}

std::string	Contact::show_last_name(void)
{
	return (this->last_name);
}

std::string	Contact::show_nickname(void)
{
	return (this->nickname);
}

std::string	Contact::show_phone_num(void)
{
	return (this->phone_num);
}

std::string	Contact::show_secret(void)
{
	return (this->secret);
}

