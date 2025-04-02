/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:59:50 by mbirou            #+#    #+#             */
/*   Updated: 2025/04/02 09:52:57 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <spellBook.hpp>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		PRINT RED BOLD "Error, usage: " AND argv[0] AND " <expression>" CENDL;
		return (1);
	}
	try
	{
		RPN::rpn(argv[1]);
	}
	catch (std::exception &e)
	{
		PRINT e.what() CENDL;
	}
}