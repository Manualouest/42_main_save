/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:59:50 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/07 15:05:22 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <spellBook.hpp>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		PRINT RED BOLD "Error, usage: " AND argv[0] AND "<expression>" CENDL;
		return (1);
	}
	RPN::rpn(argv[1]);
}