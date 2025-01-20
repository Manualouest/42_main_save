/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:54:59 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/20 11:32:28 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iterator>
#include <iostream>

template<typename T>
int	easyfind(T container, int n)
{
	int	i = 0;
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == n)
			return (i);
		++i;
	}
	return (-1);
}

template<typename T>
std::string	printContainer(T container)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		PRINT CYN BOLD AND *it;
		if (++it != container.end())
			PRINT ", ";
		--it;
	}
	return ("");
}
