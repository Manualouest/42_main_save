/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:25:47 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/25 20:18:10 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->oldest_index = 0;
	this->len = 0;
	std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called" << std::endl;
}

static std::string get_input(char *msg)
{
	std::string	input;

	std::cout << msg;
	std::getline(std::cin, input);
	while (input.size() == 0)
	{
		if (input == "")
			return ("");
		std::cout << "\033[39;1mPlease enter something :(\033[0m" << std::endl << msg;
		std::getline(std::cin, input, '\n');
	}
	return (input);
}

bool	PhoneBook::add(void)
{
	std::string	first_name = get_input((char *)"\033[39;1mPlease enter contact first name: \033[0m");
	std::string	last_name = get_input((char *)"\033[39;1mPlease enter contact last name: \033[0m");
	std::string	nickname = get_input((char *)"\033[39;1mPlease enter their nickname: \033[0m");
	std::string	number = get_input((char *)"\033[39;1mPlease enter contact number: \033[0m");
	std::string	secret = get_input((char *)"\033[39;1mNow put the darkest secret about them: \033[0m");
	if (first_name == "" || last_name == "" || nickname == "" || number == "" || secret == "")
		return (false);
	this->contacs[this->oldest_index].set_contact(first_name, last_name, nickname, number, secret);
	this->oldest_index = (this->oldest_index + 1) % 8;
	this->len += this->len < 7;
	return (true);
}

std::string	format_string(std::string text)
{
	if (text.size() == 10)
		return (text);
	else if (text.size() > 10)
		return (text.substr(0, 9).append("."));
	return (text);
}

void	PhoneBook::show(void)
{
	const char	*indexs[8] = {"🯰","🯱","🯲","🯳","🯴","🯵","🯶","🯷"};

	std::cout << "\033[31m╔══════════╦══════════╦══════════╦══════════╗" << std::endl
				<< "║     \033[32mindex\033[31m║\033[32mfirst name\033[31m║"
				<< " \033[32mlast name\033[31m║  \033[32mnickname\033[31m║" << std::endl
				<< "╠══════════╬══════════╬══════════╬══════════╣" << std::endl;
	for (int i = 0; i < this->len; i++)
	{
		std::cout << "\033[31m║\033[32m" << std::setw(13) << indexs[i] << "\033[31m║\033[32m";
		std::cout << std::setw(10) << format_string(this->contacs[i].get_first_name()) << "\033[31m║\033[32m";
		std::cout << std::setw(10) << format_string(this->contacs[i].get_last_name()) << "\033[31m║\033[32m";
		std::cout << std::setw(10) << format_string(this->contacs[i].get_nickname()) << "\033[31m║\033[32m";
		std::cout << std::endl;
	}
	for (int i = this->len; i < 8; i++)
		std::cout << "\033[31m║\033[32m"  << std::setw(13) << indexs[i] << "\033[31m║" << std::setw(13)
			<< "║" << std::setw(13) << "║" << std::setw(13) << "║" << std::endl;
	std::cout << "╚══════════╩══════════╩══════════╩══════════╝\033[39m" << std::endl;
}

bool	PhoneBook::search(void)
{
	std::string	input;
	int			int_index;

	this->show();
	input = get_input((char *)"\033[39;1mPlease enter the index you are searching for: \033[0m");
	if (input == "")
		return (false);
	int_index = std::atoi(input.c_str());
	if (input.length() != 1 || int_index < 0 || int_index >= this->len)
	{
		if (input.length() != 1)
			std::cout << "Index is invalid, try again next time." << std::endl;
		if (int_index < 0 || int_index >= this->len)
			std::cout << "Index is out of range, try again next time." << std::endl;
		return (true);
	}
	std::cout << "First name     :" << this->contacs[int_index].get_first_name() << std::endl
		<< "Last name      :" << this->contacs[int_index].get_last_name() << std::endl
		<< "Nickname       :" << this->contacs[int_index].get_nickname() << std::endl
		<< "Number         :" << this->contacs[int_index].get_phone_num() << std::endl
		<< "Darkest secret :" << this->contacs[int_index].get_secret() << std::endl;
	return (true);
}

