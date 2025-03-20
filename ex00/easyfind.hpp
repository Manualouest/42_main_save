/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:54:59 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/20 10:42:01 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iterator>
#include <exception>
#include <iostream>

template<typename T>
typename T::iterator	easyfind(T container, int n)
{
	if (std::find(container.begin(), container.end(), n) == container.end())
		throw(std::range_error(RED BOLD "not found." CLR));
	return (std::find(container.begin(), container.end(), n));
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
	PRINT CLR;
	return ("");
}
