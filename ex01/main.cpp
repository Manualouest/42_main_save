/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:38:24 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/27 18:30:30 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	do
	{
		if (input == "ADD")
		{
			std::cout << "\033c";
			if (phonebook.add() == false)
				break ;
		}
		else if (input == "SEARCH")
		{
			std::cout << "\033c";
			if (phonebook.search() == false)
				break ;
		}
		std::cout << std::endl << std::endl;
		if (input != "ADD" && input != "SEARCH")
			std::cout << "\033c";		
		std::cout	<< "\033[37;49;1m╭─\033[37;49;1;4m───\033[0m\033[37;49;1m───\033[37;49;1;4m─\033[0m\033[37;49;1m───\033[37;49;1;4m─\033[0m\033[37;49;1m─\033[37;49;1;4m─────\033[0m\033[37;49;1m─\033[37;49;1;4m─\033[0m\033[37;49;1m───\033[37;49;1;4m─\033[0m\033[37;49;1m─\033[37;49;1;4m───\033[0m\033[37;49;1m───\033[37;49;1;4m───\033[0m\033[37;49;1m───\033[37;49;1;4m─────\033[0m\033[37;49;1m─\033[37;49;1;4m─────\033[0m\033[37;49;1m─\033[37;49;1;4m─\033[0m\033[37;49;1m───\033[37;49;1;4m─\033[0m\033[37;49;1m─╮" << std::endl
					<< "\033[37;49;1m│\033[39;49;1m|  _`\\| | | |  _  | | | |  _`\\|  _`\\|  _  |  _  | | | |" << std::endl
					<< "\033[37;49;1m│\033[39;49;1m| |_| | |_| | | | | `\\| | |_| | |_| | | | | | | | |/ /" << std::endl
					<< "\033[37;49;1m│\033[39;49;1m| ,__/|  _  | | | | , ` |  _ <|  _ <| | | | | | | , <  " << std::endl
					<< "\033[37;49;1m│\033[39;49;1m| |   | | | | |_| | |`\\ | |_| | |_| | |_| | |_| | |\\`\\ " << std::endl
					<< "\033[37;49;1m│\033[39;49;1m|_|   |_| |_|_____|_| |_|____/|____/|_____|_____|_| |_|" << std::endl
					<< "\033[37;49;1m│ADD    : add a new contact to your phone book or, if you have more than 8, replace the oldest one." << std::endl
					<< "│SEARCH : shows you your contact list and allow you to see their details." << std::endl
					<< "│EXIT   : ends the phone book." << std::endl
					<< "├─────────────────────────────╯" << std::endl
					<< "\033[37;49;1m│\033[37;49m 🯁🯂🯃 \033[0m";
		getline(std::cin, input);
	} while (!std::cin.eof() && input != "EXIT");
	std::cout << "\033[39;1mPhonebook closing, goodbye\033[0m" << std::endl;
}
