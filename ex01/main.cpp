/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:38:24 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/27 13:15:37 by mbirou           ###   ########.fr       */
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
		if (input == "ADD" || input == "SEARCH")
			std::cout << "\033[39;1mUseable commands: ADD, SEARCH, EXIT\033[0m" << std::endl;
		else
			std::cout << "\033c\033[39;1mUseable commands: ADD, SEARCH, EXIT\033[0m" << std::endl;
		getline(std::cin, input);
	} while (!std::cin.eof() && input != "EXIT");
	std::cout << "\033c\033[39;1mPhonebook closing, goodbye\033[0m" << std::endl;
}
