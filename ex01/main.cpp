/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:01:30 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/19 17:32:38 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <spellBook.hpp>
#include "Iter.hpp"

void	printUpper(char c)
{
	PRINT (char)toupper(c);
}

void	printLower(char c)
{
	PRINT (char)tolower(c);
}

void	printChar(char c)
{
	PRINT c;
}

void	doubleInt(int n)
{
	PRINT n * 2 AND ", ";
}

void	halveInt(int n)
{
	PRINT n / 2 AND ", ";
}

void	printNum(int n)
{
	PRINT n AND ", ";
}

int	main()
{
	{
		char	str[] = "Hello World!\n";
		PRINT CYN BOLD "original string: " CLR BOLD;
		iter(str, 13, &printChar);
		PRINT CYN BOLD "in CAPS:	 " CLR BOLD;
		iter(str, 13, &printUpper);
		PRINT CYN BOLD "in lower case:	 " CLR BOLD;
		iter(str, 13, &printLower);
	}
	{
		NEWL;
		int	nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		PRINT CYN BOLD "original array: " CLR BOLD;
		iter(nums, 11, &printNum);
		PRINT CYN BOLD ENDL AND "doubled:	" CLR BOLD;
		iter(nums, 11, &doubleInt);
		PRINT CYN BOLD ENDL AND "halved:		" CLR BOLD;
		iter(nums, 11, &halveInt);
		NEWL;
	}
}