/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:59:35 by mbirou            #+#    #+#             */
/*   Updated: 2025/04/02 09:54:20 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1 || !std::strcmp(argv[1], "-p"))
		PRINT RED BOLD "usage: " AND argv[0] AND " <numbers> <option (-p)>" CENDL;
	else
	{
		try
		{
			PmergeMe::sort(argc - 1, &argv[1]);
		}
		catch (std::exception &e)
		{
			PRINT e.what() CENDL;
		}
	}
}