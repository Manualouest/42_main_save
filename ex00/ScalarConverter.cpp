/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:15:20 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/05 12:08:18 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator =(const ScalarConverter &rhs)
{
	(void)rhs;
	return (*this);
}



void	ScalarConverter::convert(const std::string &param)
{
	PRINT CYN BOLD "int:     ";
	if (std::atoll(param.c_str()) > 2147483647 || std::atoll(param.c_str()) < 2147483648 || param == "nan" || param.find("inf") != std::string::npos)
		PRINT 
	PRINT CYN BOLD "char:    ";
	PRINT CYN BOLD "float:   ";
	PRINT CYN BOLD "double:  ";
}
