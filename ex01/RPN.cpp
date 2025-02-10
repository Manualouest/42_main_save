/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:04:20 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/07 16:25:01 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<std::string>	split(const std::string &expression)
{
	std::stack<std::string>	rsplit;
	std::stack<std::string>	split;
	for (int pos = 0; pos < expression.length() && ; pos = expression.find_first_not_of("0123456789./*-+", pos))
	
	return (split);
}

void	RPN::rpn(const std::string &expression)
{
	// std::stack<int> nums;
	std::stack<std::string> splitExp = split(expression);
	for (std::string exp = splitExp.top(); splitExp.size() > 0; splitExp.pop(), exp = splitExp.top())
		PRINT exp CENDL;
}
