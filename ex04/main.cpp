/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:13:05 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/01 16:51:29 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int argc, char **argv)
{
	Replace	Replace;

	if (argc != 4 || !argv[1][0] || !argv[2][0] || !argv[3][0])
	{
		std::cout	<< "\033[31;1mplease enter the right agruments\033[0m 😾" << std::endl
					<< "\t- \033[31;1mname of the file to open\033[0m" << std::endl
					<< "\t- \033[31;1mstring to be replaced in the file\033[0m" << std::endl
					<< "\t- \033[31;1mstring to for the replacement\033[0m" << std::endl;
		return (1);
	}
	if (!Replace.setup(argv[1], argv[2], argv[3]))
		return (1);
	Replace.execute();
}
