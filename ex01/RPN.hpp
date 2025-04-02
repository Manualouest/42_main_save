/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:26:11 by mbirou            #+#    #+#             */
/*   Updated: 2025/04/02 09:52:01 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <spellBook.hpp>

class RPN
{
	public:
		static void	rpn(const std::string &expression);

	private:
		RPN();
		RPN(const RPN &src);
		RPN	&operator =(const RPN &rhs);
		~RPN();

		static std::stack<double>	_nums;

		static void	_doOperation(double(*f)(double, double));
	
		class invalidFormatException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class invalidCharException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};
