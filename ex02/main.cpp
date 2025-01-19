/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:37:03 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/19 19:47:27 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <spellBook.hpp>
#include "Array.hpp"

int	main()
{
	
	Array<char> a(10);
	a[1] = '1';
	Array<char> b = a;
	Array<char> c(15);
	b = c;
	PRINT a ENDL AND b ENDL;
	try
	{
		a[10] = 1;
	}
	catch (std::exception &e)
	{
		PRINT RED AND e.what() CENDL;
	}
	try
	{
		a[-1] = 1;
	}
	catch (std::exception &e)
	{
		PRINT RED AND e.what() CENDL;
	}
}