/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:04:20 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/21 12:15:49 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	printReadable(const std::string &expression);

std::stack<int>	RPN::_nums = std::stack<int>();

int _add(int a, int b) {return (a + b);}
int _sub(int a, int b) {return (a - b);}
int _mul(int a, int b) {return (a * b);}
int _div(int a, int b) {return (a / b);}

void	RPN::_doOperation(int(*operation)(int, int))
{
	if (_nums.size() < 2)
		throw (RPN::invalidFormatException());
	int result = _nums.top();
	_nums.pop();
	result = operation(_nums.top(), result);
	_nums.pop();
	_nums.push(result);
}

void	RPN::rpn(const std::string &expression)
{
	for (std::string::const_iterator it = expression.begin(); it != expression.end(); ++it)
	{
		switch (*it)
		{
			case ' ':
				break ;
			case '0':case '1':case '2':case '3':case '4':
			case '5':case '6':case '7':case '8':case '9':
				_nums.push(*it - '0');
				break ;
			case '+':
				_doOperation(_add);
				break ;
			case '-':
				_doOperation(_sub);
				break ;
			case '*':
				_doOperation(_mul);
				break ;
			case '/':
				_doOperation(_div);
				break ;
			default:
				throw(RPN::invalidCharException());
		}
	}
	switch (_nums.size())
	{
		case 1:
			printReadable(expression);
			PRINT CYN BOLD AND _nums.top() CENDL;
			break ;
		default:
			throw(RPN::invalidFormatException());
	}
}

void	printReadable(const std::string &expression)
{
	std::string	tpexpr = expression;
	bool		isFirst = true;

	PRINT BOLD;
	while (tpexpr.find_first_of("+-*/") != std::string::npos)
	{
		if (isFirst)
			PRINT tpexpr[tpexpr.find_last_not_of("+-*/ ", tpexpr.find_last_not_of("+-*/ ", tpexpr.find_first_of("+-*/")) - 1)] AND " ";
		PRINT tpexpr[tpexpr.find_first_of("+-*/")] AND " ";
		PRINT tpexpr[tpexpr.find_last_not_of("+-*/ ", tpexpr.find_first_of("+-*/"))] AND " ";
		if (isFirst)
			tpexpr.erase(tpexpr.find_last_not_of("+-*/ ", tpexpr.find_last_not_of("+-*/ ", tpexpr.find_first_of("+-*/")) - 1), 1);
		tpexpr.erase(tpexpr.find_last_not_of("+-*/ ", tpexpr.find_first_of("+-*/")), 1);
		tpexpr.erase(tpexpr.find_first_of("+-*/"), 1);
		if (isFirst)
			isFirst = false;
	}
	PRINT "= ";
}

const char *RPN::invalidFormatException::what() const throw()
{
	return (RED BOLD "Format is invalid." CLR);
}

const char *RPN::invalidCharException::what() const throw()
{
	return (RED BOLD "Invalid character found." CLR);
}
