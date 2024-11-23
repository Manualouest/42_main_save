/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:25:47 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/23 20:16:28 by mbirou           ###   ########.fr       */
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

std::string	get_input(char *msg)
{
	std::string	input;
	std::cout << msg;
	std::getline(std::cin, input);
	while (input.size() == 0)
	{
		std::cout << "Please enter something :(" << std::endl << msg;
		std::getline(std::cin, input, '\n');
	}
	return (input);
}

void	PhoneBook::add(void)
{
	std::string	first_name = get_input((char *)"Please enter contact first name: ");
	std::string	last_name = get_input((char *)"Please enter contact last name: ");
	std::string	nickname = get_input((char *)"Please enter their nickname: ");
	std::string	number = get_input((char *)"Please enter contact number: ");
	std::string	secret = get_input((char *)"Now put a dark secret about: ");
	this->contacs[this->oldest_index].set_contact(first_name, last_name, nickname, number, secret);
	this->oldest_index = (this->oldest_index + 1) % 8;
	if (this->len < 8)
		this->len += 1;
}

std::string	format_string(std::string text)
{
	if (text.size() == 10)
		return (text);
	else if (text.size() > 10)
		return (text.substr(0, 9).append("."));
	else
		return (text.append("         ").substr(0, 10));
}

void	PhoneBook::search(void)
{
	const char	*indexs[8] = {"🯰","🯱","🯲","🯳","🯴","🯵","🯶","🯷"};
	std::cout << "╠══════════╬══════════╬══════════╬══════════╣" << std::endl;
	for (int i = 0; i < this->len; i++)
		std::cout << "║" << indexs[i] << "         "\
			<< "║" << format_string(this->contacs[i].show_first_name())\
			<< "║" << format_string(this->contacs[i].show_last_name())\
			<< "║" << format_string(this->contacs[i].show_nickname())\
			<< "║" << std::endl;
	for (int i = this->len; i < 8; i++)
		std::cout << "║" << indexs[i] << "         "\
			<< "║" << "          "\
			<< "║" << "          "\
			<< "║" << "          " << "║" << std::endl;
	std::cout << "╚══════════╩══════════╩══════════╩══════════╝" << std::endl;
}

