/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:15:20 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/04 16:45:24 by mbirou           ###   ########.fr       */
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
	PRINT CYN BOLD "char: " AND (std::isprint(std::atoi(param.c_str())) ? (&(char){std::atoi(param.c_str())}) : "Non displayable") ENDL AND "int: " AND std::atoi(param.c_str()) ENDL AND "float: " AND (float)std::atof(param.c_str()) AND "f" ENDL AND "double: " AND std::atof(param.c_str()) AND CLR ENDL;
}

// (char)std::atoi(param.c_str()) = 'a'
// (char *{(char)std::atoi(param.c_str())})