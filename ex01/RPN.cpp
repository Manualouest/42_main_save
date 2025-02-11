/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:04:20 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/10 17:30:09 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<std::string>	split(const std::string &expression)
{
	std::stack<std::string>	rsplit;
	std::stack<std::string>	split;
	for (std::size_t pos = 0; pos < expression.length(); pos = expression.find_first_not_of("0123456789./*-+", pos))
	{
		PRINT pos AND ", " AND expression.substr(pos, expression.find_first_not_of("0123456789./*-+", pos + 1) + pos) ENDL;
		rsplit.push(expression.substr(pos + (pos > 0), expression.find_first_not_of("0123456789./*-+", pos + 1) + pos));
		pos += 1;
	}
	rsplit.push("");
	for (std::string exp = rsplit.top(); rsplit.size() > 0; exp = rsplit.top(), rsplit.pop())
	{
		split.push(exp);
	}
	return (split);
}

void	RPN::rpn(const std::string &expression)
{
	// std::stack<int> nums;
	std::stack<std::string> splitExp = split(expression);
	for (std::string exp = splitExp.top(); splitExp.size() > 0; splitExp.pop(), exp = splitExp.top())
		PRINT "'" AND exp AND "'" CENDL;
}
