/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:13:05 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/03 18:51:27 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	main(int argc, char **argv)
{
	Sed	Sed;

	if (argc != 4 || !argv[1][0] || !argv[2][0] || !argv[3][0])
	{
		std::cout	<< "\033[31;1mplease enter the right arguments\033[0m 😾" << std::endl
					<< "\t- \033[31;1mname of the file to open\033[0m" << std::endl
					<< "\t- \033[31;1mstring to be replaced in the file\033[0m" << std::endl
					<< "\t- \033[31;1mstring to for the replacement\033[0m" << std::endl;
		return (1);
	}
	if (!Sed.setup(argv[1], argv[2], argv[3]))
		return (1);
	Sed.execute();
}
