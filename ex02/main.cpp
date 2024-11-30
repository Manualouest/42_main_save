/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:38:37 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/30 18:45:25 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int	main(void)
{
	std::string	string;
	std::string	*stringPTR;
	std::string	&stringREF = string;

	string = "HI THIS IS BRAIN";
	stringPTR = &string;
	std::cout	<< std::setiosflags(std::ios::left) << "\x1b[1;4mThis is the adresse\x1b[0m:" << std::endl
				<< std::setw(33) << "\t-\x1b[1;4mof the variable\x1b[0m" << ": " << &string << std::endl
				<< std::setw(33) << "\t-\x1b[1;4mheld by the pointer\x1b[0m" << ": " << stringPTR << std::endl
				<< std::setw(33) << "\t-\x1b[1;4mof the reference\x1b[0m" << ": " << &stringREF << std::endl;
	std::cout	<< std::endl << "\x1b[1;4mThis is the value inside\x1b[0m:" << std::endl
				<< std::setw(33) << "\t-\x1b[1;4mof the variable\x1b[0m" << ": " << string << std::endl
				<< std::setw(33) << "\t-\x1b[1;4mheld by the pointer\x1b[0m" << ": " << *stringPTR << std::endl
				<< std::setw(33) << "\t-\x1b[1;4mof the reference\x1b[0m" << ": " << stringREF << std::endl;
	string = "Hello";
	std::cout	<< std::endl << "\x1b[1;4mchanging the variable\x1b[0m:" << std::endl
				<< std::setw(33) << "\t-\x1b[1;4min the variable\x1b[0m" << ": " << string << std::endl
				<< std::setw(33) << "\t-\x1b[1;4min the pointer\x1b[0m" << ": " << *stringPTR << std::endl
				<< std::setw(33) << "\t-\x1b[1;4min the reference\x1b[0m" << ": " << stringREF << std::endl;
	*stringPTR = "Hola";
	std::cout	<< std::endl << "\x1b[1;4mchanging the pointer\x1b[0m:" << std::endl
				<< std::setw(33) << "\t-\x1b[1;4min the variable\x1b[0m" << ": " << string << std::endl
				<< std::setw(33) << "\t-\x1b[1;4min the pointer\x1b[0m" << ": " << *stringPTR << std::endl
				<< std::setw(33) << "\t-\x1b[1;4min the reference\x1b[0m" << ": " << stringREF << std::endl;
	stringREF = "Iaorana";
	std::cout	<< std::endl << "\x1b[1;4mchanging the reference\x1b[0m:" << std::endl
				<< std::setw(33) << "\t-\x1b[1;4min the variable\x1b[0m" << ": " << string << std::endl
				<< std::setw(33) << "\t-\x1b[1;4min the pointer\x1b[0m" << ": " << *stringPTR << std::endl
				<< std::setw(33) << "\t-\x1b[1;4min the reference\x1b[0m" << ": " << stringREF << std::endl;
}