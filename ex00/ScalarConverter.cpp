/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:15:20 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/07 11:12:33 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	parseParam(const std::string &param)
{
	int	coma = 0;
	if (param == "nan" || param == "nanf" || param == "inf" || param == "inff"
		|| param == "+inf" || param == "-inf" || param == "+inff" || param == "-inff")
		return (2);
	if (param.length() == 1)
		return (1);
	char * ptr;
	double	tpNum = std::strtod(param.c_str(), &ptr);
	if ((*ptr != 0 && *ptr != 'f'))
		return (0);
	return (1);
}

int	detectType(const std::string &param, int parser)
{
	double	tpNum = std::strtod(param.c_str(), NULL);
	if (errno == ERANGE && parser == 1)
		return (NONE);
	if (((tpNum < 0 && (tpNum < -__FLT_MAX__ || tpNum > -__FLT_MIN__)
			|| (tpNum > 0 && (tpNum > __FLT_MAX__ || tpNum < __FLT_MIN__)))
			&& param.find('f') != std::string::npos))
		return (DOUBLE);
	if (param.length() == 1 && !std::isdigit(param[0]))
		return (CHAR);
	if (param == "nan" || param == "inf" || param == "+inf" || param == "-inf")
		return (DOUBLE);
	if (param == "nanf" || param == "inff" || param == "+inff" || param == "-inff")
		return (FLOAT);
	if (param.find('f') != std::string::npos)
		return (FLOAT);
	if (param.find('.') != std::string::npos
		|| tpNum > INT_MAX || tpNum < INT_MIN)
		return (DOUBLE);
	return (INT);
}

void	ScalarConverter::convert(const std::string &param)
{
	int	parser = parseParam(param);
	if (!parser)
		throw (std::invalid_argument(RED BOLD "Please enter a valid char, int, float or double.😡" CLR));
	errno = 0;
	switch (int paramType = detectType(param, parser))
	{
		case CHAR:
		{
			ScalarConverter::print((char)(param.c_str()[0]), 1);
			break ;
		}
		case INT:
		{
			ScalarConverter::print(static_cast<int>(std::strtod(param.c_str(), NULL)), 1);
			break ;
		}
		case FLOAT:
		{
			ScalarConverter::print(static_cast<float>(std::atof(param.c_str())), (param.length() - param.find('.') - 2)  * (param.find('.') != std::string::npos));
			break ;
		}
		case DOUBLE:
		{
			ScalarConverter::print(std::strtod(param.c_str(), NULL), (param.length() - param.find('.') - 1) * (param.find('.') != std::string::npos));
			break ;
		}
		default:
		{
			PRINT CYN BOLD "char: impossible" ENDL AND "int: impossible" ENDL
				AND "float: inff" ENDL AND "double: inf" CENDL;
		}
	}
}

