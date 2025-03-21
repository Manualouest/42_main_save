/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:14:23 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/21 11:18:35 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <map>
#include <iostream>
#include <spellBook.hpp>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		PRINT RED BOLD "Invalid parameters" CENDL;
		PRINT RED BOLD UNDL "Usage:" RED BOLD " " AND argv[0] AND " <input_file>" CENDL;
		return (1);
	}
	try
	{
		BitcoinExchange::getRates(argv[1]);
	}
	catch (std::exception &e)
	{
		PRINT e.what() CENDL;
	}
	return (0);
}