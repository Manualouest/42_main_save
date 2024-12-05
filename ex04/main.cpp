/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:13:05 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/04 12:33:05 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout	<< "\033[31;1mplease enter the right arguments\033[0m 😾" << std::endl
					<< "\t- \033[31;1mname of the file to open\033[0m" << std::endl
					<< "\t- \033[31;1mstring to be replaced in the file\033[0m" << std::endl
					<< "\t- \033[31;1mstring to for the replacement\033[0m" << std::endl;
		return (1);
	}
	try
	{
		Sed	sed(argv[1], argv[2], argv[3]);
		sed.execute();
		std::cout << "\033[32;1mFile successfully created 😺\033[0m";
	}
	catch (std::string error)
	{
		std::cout << error << std::endl;
	}
}
