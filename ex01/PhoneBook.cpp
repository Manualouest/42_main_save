/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:25:47 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/27 18:25:12 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_oldest_index = 0;
	this->_len = 0;
	std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called" << std::endl;
}

std::string PhoneBook::_get_input(char *msg) const
{
	std::string	input;
	int			count;

	std::cout << msg;
	std::getline(std::cin, input);
	count = 0;
	while (!std::cin.eof() &&input.size() == 0)
	{
		if (std::cin.eof())
			return ("");
		if (count < 5)
			std::cout << "\033[39;1mPlease enter something :(\033[0m" << std::endl;
		else if (count < 10)
			std::cout << "\033[39;1mPlease enter something >:(\033[0m" << std::endl;
		else if (count < 24)
			std::cout << "\033[31;1mPlease enter something 😡\033[0m" << std::endl;
		else if (count < 25)
			std::cout	<< "\033[31;1mI KNOW WHERE YOU ARE:" << std::endl
						<< "\033[31;1;4m45.655108974298685, 0.1589656362467441\033[0m" << std::endl;
		else
		{
			std::cout << "\033[31;1;4mI AM COMING FOR YOU 🫵😡\033[0m" << std::endl;
			return ("");
		}
		std::cout << msg;
		std::getline(std::cin, input, '\n');
		count ++;
	}
	return (input);
}

bool	PhoneBook::add(void)
{
	std::string	first_name = PhoneBook::_get_input((char *)"\033[39;1mPlease enter contact first name: \033[0m");
	if (!first_name.length())
		return (false);
	std::string	last_name = PhoneBook::_get_input((char *)"\033[39;1mPlease enter contact last name: \033[0m");
	if (!last_name.length())
		return (false);
	std::string	nickname = PhoneBook::_get_input((char *)"\033[39;1mPlease enter their nickname: \033[0m");
	if (!nickname.length())
		return (false);
	std::string	number = PhoneBook::_get_input((char *)"\033[39;1mPlease enter contact number: \033[0m");
	if (!number.length())
		return (false);
	std::string	secret = PhoneBook::_get_input((char *)"\033[39;1mNow put the darkest secret about them: \033[0m");
	if (std::cin.eof() || !secret.length())
		return (false);
	this->_contacts[this->_oldest_index].set_contact(first_name, last_name, nickname, number, secret);
	std::cout << "\033c";
	std::cout << "\033[30;47;1mContact added:\033[0m" << std::endl;
	this->_ShowContact(this->_oldest_index);
	this->_oldest_index = (this->_oldest_index + 1) % 8;
	this->_len += this->_len < 8;
	return (true);
}

std::string	PhoneBook::PhoneBook::_format_string(std::string text) const
{
	if (text.size() == 10)
		return (text);
	else if (text.size() > 10)
		return (text.substr(0, 9).append("."));
	return (text);
}

void	PhoneBook::_ShowContacts(void) const
{
	const char	*indexs[8] = {"🯰","🯱","🯲","🯳","🯴","🯵","🯶","🯷"};

	std::cout << "\033[30;47;1m╔══════════╦══════════╦══════════╦══════════╗" << std::endl
				<< "║     \033[30;47mindex\033[30;47;1m║\033[30;47mfirst name\033[30;47;1m║"
				<< " \033[30;47mlast name\033[30;47;1m║  \033[30;47mnickname\033[30;47;1m║" << std::endl
				<< "╠══════════╬══════════╬══════════╬══════════╣" << std::endl;
	for (int i = 0; i < this->_len; i++)
	{
		std::cout << "\033[30;47;1m║\033[30;47m" << std::setw(12) << indexs[i] << "\033[30;47;1m ║\033[30;47m";
		std::cout << std::setw(10) << PhoneBook::_format_string(this->_contacts[i].get_first_name()) << "\033[30;47;1m║\033[30;47m";
		std::cout << std::setw(10) << PhoneBook::_format_string(this->_contacts[i].get_last_name()) << "\033[30;47;1m║\033[30;47m";
		std::cout << std::setw(10) << PhoneBook::_format_string(this->_contacts[i].get_nickname()) << "\033[30;47;1m║\033[30;47m";
		std::cout << std::endl;
	}
	for (int i = this->_len; i <= 7; i++)
		std::cout << "\033[30;47;1m║\033[30;47m"  << std::setw(12) << indexs[i] << "\033[30;47;1m ║" << std::setw(13)
			<< "║" << std::setw(13) << "║" << std::setw(13) << "║" << std::endl;
	std::cout << "╚══════════╩══════════╩══════════╩══════════╝\033[0m" << std::endl;
}

void	PhoneBook::_ShowContact(int index) const
{
	size_t	TabWidth;

	TabWidth = 1;
	if (this->_contacts[index].get_first_name().length() > TabWidth)
		TabWidth = this->_contacts[index].get_first_name().length();
	if (this->_contacts[index].get_last_name().length() > TabWidth)
		TabWidth = this->_contacts[index].get_last_name().length();
	if (this->_contacts[index].get_nickname().length() > TabWidth)
		TabWidth = this->_contacts[index].get_nickname().length();
	if (this->_contacts[index].get_phone_num().length() > TabWidth)
		TabWidth = this->_contacts[index].get_phone_num().length();
	if (this->_contacts[index].get_secret().length() > TabWidth)
		TabWidth = this->_contacts[index].get_secret().length();
	std::cout << "\033[30;47;1m╔═══════════════╦";
	for (size_t i = 0; i < TabWidth; i++)
		std::cout << "═";
	std::cout << "╗\033[30;47m" << std::endl << std::setiosflags(std::ios::left);
	std::cout	<< "\033[30;47;1m║\033[30;47m" << std::setw(15) << "index" << "\033[30;47;1m║\033[30;47m"
					<< std::setw(TabWidth) << index  << "\033[30;47;1m║\033[30;47m" << std::endl
				<< "\033[30;47;1m║\033[30;47m" << std::setw(15) << "First name" << "\033[30;47;1m║\033[30;47m"
					<< std::setw(TabWidth) << this->_contacts[index].get_first_name() << "\033[30;47;1m║\033[30;47m" << std::endl
				<< "\033[30;47;1m║\033[30;47m" << std::setw(15) << "Last name" << "\033[30;47;1m║\033[30;47m"
					<< std::setw(TabWidth) << this->_contacts[index].get_last_name() << "\033[30;47;1m║\033[30;47m" << std::endl
				<< "\033[30;47;1m║\033[30;47m" << std::setw(15) << "Nickname" << "\033[30;47;1m║\033[30;47m"
					<< std::setw(TabWidth) << this->_contacts[index].get_nickname() << "\033[30;47;1m║\033[30;47m" << std::endl
				<< "\033[30;47;1m║\033[30;47m" << std::setw(15) << "Number" << "\033[30;47;1m║\033[30;47m"
					<< std::setw(TabWidth) << this->_contacts[index].get_phone_num() << "\033[30;47;1m║\033[30;47m" << std::endl
				<< "\033[30;47;1m║\033[30;47m" << std::setw(15) << "Darkest secret" << "\033[30;47;1m║\033[30;47m"
					<< std::setw(TabWidth) << this->_contacts[index].get_secret() << "\033[30;47;1m║\033[30;47m" << std::endl;
	std::cout << "\033[30;47;1m╚═══════════════╩";
	for (size_t i = 0; i < TabWidth; i++)
		std::cout << "═";
	std::cout << "╝\033[0m" << std::resetiosflags(std::ios::left);
}

bool	PhoneBook::search(void)
{
	std::string	input;
	int			int_index;

	this->_ShowContacts();
	std::cout << "\033[39;49;1mPlease enter the index you are searching for: \033[0m";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return (false);
	int_index = std::atoi(input.c_str());
	if (input.length() != 1 || !std::isdigit(input[0]) || int_index < 0 || int_index >= this->_len)
	{
		if (input.length() != 1 || !std::isdigit(input[0]) || int_index < 0 || int_index > 7)
			std::cout << "\033[39;49;1mInvalid input, try again next time.\033[0m" << std::endl;
		else if (int_index >= this->_len)
			std::cout << "\033[39;49;1mYou don't have that many contacts.\033[0m" << std::endl;
		return (true);
	}
	std::cout << "\033c";
	this->_ShowContacts();
	this->_ShowContact(int_index);
	return (true);
}

