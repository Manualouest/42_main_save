/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:41:56 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/20 09:59:25 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <spellBook.hpp>
#include "Span.hpp"
#include <vector>
#include <ctime>

std::vector<int> vecGen(int len)
{
	std::srand(std::time(NULL));
	std::vector<int>	vector (len, 0);
	int					rNum;
	for (int i = 0; i < len; ++i)
	{
		while (rNum = std::rand(), *std::find(vector.begin(), vector.end(), rNum) == rNum)
			;
		vector[i] = rNum;
	}
	return (vector);
}

int	main()
{
	NEWL;
	{
		Span span(2);
		span.addNumber(1);
		PRINT BOLD "Safety checks (" AND span AND "):" CENDL;
		PRINT TAB BOLD "Shortest and longest span safety:" CENDL;
		PRINT TAB TAB BOLD "Shortest: " CENDL;
		try
		{
			span.shortestSpan();
		}
		catch (std::exception &e)
		{
			PRINT TAB TAB TAB AND e.what();
		}
		PRINT TAB TAB BOLD "Longest: " CENDL;
		try
		{
			span.longestSpan();
		}
		catch (std::exception &e)
		{
			PRINT TAB TAB TAB AND e.what();
		}
		NEWL;
		PRINT TAB BOLD "addNumber check:" CENDL;
		PRINT TAB TAB BOLD "adding 2:" CENDL;
		span.addNumber(2);
		PRINT TAB TAB TAB AND span CENDL;
		NEWL;
		PRINT TAB TAB BOLD "adding 42:" CENDL;
		try
		{
			span.addNumber(42);
		}
		catch (std::exception &e)
		{
			PRINT TAB TAB TAB AND e.what();
		}
		NEWL;
		PRINT TAB BOLD "addRange check:" CENDL;
		try
		{
			std::vector<int> vec = vecGen(10);
			span.addRange(vec.begin(), vec.end());
		}
		catch (std::exception &e)
		{
			PRINT TAB TAB AND e.what();
		}
	}
	NEWL;
	{
		Span span(5);
		PRINT BOLD "Creating the same span as the exemple:" CENDL;
		span.addNumber(5);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);
		PRINT TAB AND span CENDL;
		PRINT TAB BOLD "shortest span: " CYN BOLD AND span.shortestSpan() CENDL;
		PRINT TAB BOLD "longest span: " CYN BOLD AND span.longestSpan() CENDL;
	}
	NEWL;
	{
		PRINT BOLD "Making a vector of 20000 ints and putting it inside the span:" CENDL;
		std::vector<int> vec = vecGen(20000);
		Span span(20000);
		span.addRange(vec.begin(), vec.end());
		// PRINT TAB AND span CENDL;
		PRINT TAB BOLD "shortest span: " CYN BOLD;
		PRINT span.shortestSpan() CENDL;
		PRINT TAB BOLD "longest span: " CYN BOLD AND span.longestSpan() CENDL;
	}
}
