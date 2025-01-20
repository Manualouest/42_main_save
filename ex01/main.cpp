/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:41:56 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/20 18:11:30 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <spellBook.hpp>
#include "Span.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> vecGen(int len)
{
	std::srand(std::time(NULL));
	std::vector<int>	vector (len, 0);
	int					rNum;
	for (int i = 0; i < len; ++i)
	{
		rNum = std::rand();
		while (*std::find(vector.begin(), vector.end(), rNum) == rNum)
			rNum = std::rand();
		vector[i] = rNum;
	}
	return (vector);
}

int	main()
{
	Span span(10);
	// PRINT span CENDL;
	std::vector<int> vec = vecGen(10);
	span.addRange(vec.begin(), vec.end());
	PRINT span CENDL;
	PRINT span.longestSpan() CENDL;
	PRINT span.shortestSpan() CENDL;
}
