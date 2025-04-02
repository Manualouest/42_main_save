/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:04:20 by mbirou            #+#    #+#             */
/*   Updated: 2025/04/02 09:51:56 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<double>	RPN::_nums = std::stack<double>();

double _add(double a, double b) {return (a + b);}
double _sub(double a, double b) {return (a - b);}
double _mul(double a, double b) {return (a * b);}
double _div(double a, double b) {return (a / b);}

void	RPN::_doOperation(double(*operation)(double, double))
{
	if (_nums.size() < 2)
		throw (RPN::invalidFormatException());
	double result = _nums.top();
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
			PRINT CYN BOLD AND _nums.top() CENDL;
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
