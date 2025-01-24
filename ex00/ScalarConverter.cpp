/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:15:20 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/23 11:00:45 by mbirou           ###   ########.fr       */
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
	if (param.find_first_not_of("0123456789.f+-") != std::string::npos
		|| param.find('f') != param.find_last_of('f')
		|| param.find('.') != param.find_last_of('.')
		|| param.find('+') != param.find_last_of('+')
		|| param.find('-') != param.find_last_of('-')
		|| (param.find('-') != std::string::npos
			&& param.find('+') != std::string::npos))
		return (0);
	return (1);
}

int	detectType(const std::string &param, int parser)
{
	double	tpNum = std::strtod(param.c_str(), NULL);
	if ((errno == ERANGE
		|| (tpNum > __FLT_MAX__ || tpNum < -__FLT_MAX__
			&& param.find('f') != std::string::npos)
		|| ((long int)tpNum > INT_MAX || (long int)tpNum < INT_MIN
			&& (param.find('f') == std::string::npos
				|| param.find('.') == std::string::npos)))
		&& parser == 1)
		return (NONE);
	if (param.length() == 1 && !std::isdigit(param[0]))
		return (CHAR);
	if (param == "nan" || param == "inf" || param == "+inf" || param == "-inf")
		return (DOUBLE);
	if (param == "nanf" || param == "inff" || param == "+inff" || param == "-inff")
		return (FLOAT);
	if (param.find('f') != std::string::npos)
		return (FLOAT);
	if (param.find('.') != std::string::npos)
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
			ScalarConverter::print((char)(param.c_str()[0]));
			break ;
		}
		case INT:
		{
			ScalarConverter::print(std::atoi(param.c_str()));
			break ;
		}
		case FLOAT:
		{
			if (param.length() - 2 - param.find('.') < 1
				|| param.find('.') == param.length() - 2
				|| param.find('.') == std::string::npos)
				PRINT std::fixed AND std::setprecision(1);
			ScalarConverter::print(static_cast<float>(std::atof(param.c_str())));
			break ;
		}
		case DOUBLE:
		{
			if (param.length() - 1 - param.find('.') < 1
				|| param.find('.') == param.length() - 1
				|| param.find('.') == std::string::npos)
				PRINT std::fixed AND std::setprecision(1);
			ScalarConverter::print(std::strtod(param.c_str(), NULL));
			break ;
		}
		default:
		{
			if (std::strncmp(param.c_str(), "0", 1) || std::strncmp(param.c_str(), "-0", 2) || std::strncmp(param.c_str(), "+0", 2))
				PRINT CYN BOLD "char: not printable" ENDL AND "int: 0" ENDL
					AND "float: impossible" ENDL AND "double: impossible" CENDL;
			else
				PRINT CYN BOLD "char: impossible" ENDL AND "int: impossible" ENDL
					AND "float: impossible" ENDL AND "double: impossible" CENDL;
		}
	}
}

