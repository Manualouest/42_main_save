/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:48:08 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/03 18:20:06 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
		std::cout << "\033[31;1mPlease enter \033[31;1;4mONE\033[0m\033[31;1m parameter \033[0m" << std::endl;
	else
		harl.complain(argv[1]);
	return (0);
}