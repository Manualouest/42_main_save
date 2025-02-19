/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:04:20 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/18 13:55:06 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int>	RPN::_nums = std::stack<int>();
int _add(int a, int b) {return (a + b);}
int _sub(int a, int b) {return (a - b);}
int _mul(int a, int b) {return (a * b);}
int _div(int a, int b) {return (a / b);}

void	RPN::_doOperation(int(*operation)(int, int))
{
	if (RPN::_nums.size() < 2)
		throw (RPN::invalidFormatException());
	int result = RPN::_nums.top();
	RPN::_nums.pop();
	result = operation(RPN::_nums.top(), result);
	RPN::_nums.pop();
	RPN::_nums.push(result);
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
				RPN::_nums.push(*it - '0');
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
	switch (RPN::_nums.size())
	{
		case 1:
			PRINT CYN BOLD AND RPN::_nums.top() CENDL;
			break ;
		default:
			throw(RPN::invalidFormatException());
	}
}

const char *RPN::invalidFormatException::what() const throw()
{
	return (RED BOLD "Format is invalid." CLR);
}

const char *RPN::invalidCharException::what() const throw()
{
	return (RED BOLD "Invalid character found." CLR);
}
