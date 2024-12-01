/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:38:37 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/01 11:34:18 by mbirou           ###   ########.fr       */
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
	std::cout	<< std::setiosflags(std::ios::left) << "\033[1;4mThis is the adresse\033[0m:" << std::endl
				<< std::setw(33) << "\t-\033[1;4mof the variable\033[0m" << ": " << &string << std::endl
				<< std::setw(33) << "\t-\033[1;4mheld by the pointer\033[0m" << ": " << stringPTR << std::endl
				<< std::setw(33) << "\t-\033[1;4mof the reference\033[0m" << ": " << &stringREF << std::endl;
	std::cout	<< std::endl << "\033[1;4mThis is the value inside\033[0m:" << std::endl
				<< std::setw(33) << "\t-\033[1;4mof the variable\033[0m" << ": " << string << std::endl
				<< std::setw(33) << "\t-\033[1;4mheld by the pointer\033[0m" << ": " << *stringPTR << std::endl
				<< std::setw(33) << "\t-\033[1;4mof the reference\033[0m" << ": " << stringREF << std::endl;
	string = "Hello";
	std::cout	<< std::endl << "\033[1;4mchanging the variable\033[0m:" << std::endl
				<< std::setw(33) << "\t-\033[1;4min the variable\033[0m" << ": " << string << std::endl
				<< std::setw(33) << "\t-\033[1;4min the pointer\033[0m" << ": " << *stringPTR << std::endl
				<< std::setw(33) << "\t-\033[1;4min the reference\033[0m" << ": " << stringREF << std::endl;
	*stringPTR = "Hola";
	std::cout	<< std::endl << "\033[1;4mchanging the pointer\033[0m:" << std::endl
				<< std::setw(33) << "\t-\033[1;4min the variable\033[0m" << ": " << string << std::endl
				<< std::setw(33) << "\t-\033[1;4min the pointer\033[0m" << ": " << *stringPTR << std::endl
				<< std::setw(33) << "\t-\033[1;4min the reference\033[0m" << ": " << stringREF << std::endl;
	stringREF = "Iaorana";
	std::cout	<< std::endl << "\033[1;4mchanging the reference\033[0m:" << std::endl
				<< std::setw(33) << "\t-\033[1;4min the variable\033[0m" << ": " << string << std::endl
				<< std::setw(33) << "\t-\033[1;4min the pointer\033[0m" << ": " << *stringPTR << std::endl
				<< std::setw(33) << "\t-\033[1;4min the reference\033[0m" << ": " << stringREF << std::endl;
}