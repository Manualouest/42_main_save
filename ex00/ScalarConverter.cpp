/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:15:20 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/16 20:04:42 by mbirou           ###   ########.fr       */
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
	ScalarConverter::printChar(param);
	ScalarConverter::printInt(param);
	ScalarConverter::printFloat(param);
	ScalarConverter::printDouble(param);
}

int	isValid(const std::string &param)
{
	int	coma = 0;
	if (param == "inf" || param == "+inf" || param == "-inf" || param == "nan" || param == "nanf")
		return (2);
	for (std::string::const_iterator digit = param.begin(); digit != param.end(); ++digit)
	{
		if ((!std::isdigit(*digit) && *digit != '.') || coma > 1)
			if (*digit != 'f' || (*digit == 'f' && digit + 1 != param.end()))
				return (0);
		if (*digit == '.')
			coma ++;
	}
	return (1);
}

void	ScalarConverter::printChar(const std::string &param)
{
	PRINT CYN BOLD "char:    ";
	if (isValid(param) && std::atoi(param.c_str()) < 127 && std::atoi(param.c_str()) > 0 && std::isprint(std::atoi(param.c_str())))
		PRINT CYN BOLD "'" AND static_cast<char>(std::atoi(param.c_str())) AND "'" CENDL;
	else if (!isValid(param) || std::isnan(std::atof(param.c_str())) || std::isinf(std::atof(param.c_str()))
		|| std::atol(param.c_str()) > INT_MAX || std::atol(param.c_str()) < INT_MIN)
		PRINT CYN BOLD "impossible" CENDL;
	else
		PRINT CYN BOLD "not printable" CENDL;
}

void	ScalarConverter::printInt(const std::string &param)
{
	PRINT CYN BOLD "int:     ";
	if (isValid(param) == 1 && std::atol(param.c_str()) <= INT_MAX && std::atol(param.c_str()) >= INT_MIN)
		PRINT CYN BOLD AND std::atoi(param.c_str()) CENDL;
	else
		PRINT CYN BOLD "impossible" CENDL;
}

void	ScalarConverter::printFloat(const std::string &param)
{
	errno = 0;
	double	num = (std::strtod(param.c_str(), NULL));
	if (num > __FLT_MAX__ || num < -__FLT_MAX__)
		errno = ERANGE;
	PRINT CYN BOLD "float:   ";
	if (isValid(param) && errno != ERANGE)
	{
		PRINT CYN BOLD AND static_cast<float>(num);
		if (num == static_cast<int>(num) && !std::isnan(static_cast<float>(num)) && !std::isinf(static_cast<float>(num)) && num <= 1000000)
			PRINT ".0";
		if (!std::isinf(static_cast<float>(num)))
			PRINT "f";
		PRINT CLR ENDL;
	}
	else
		PRINT CYN BOLD "impossible" CENDL;
}

void	ScalarConverter::printDouble(const std::string &param)
{
	errno = 0;
	double	num = std::strtod(param.c_str(), NULL);
	PRINT CYN BOLD "double:  ";
	if (isValid(param) && errno != ERANGE)
	{
		PRINT CYN BOLD AND num AND CLR;
		if (num == static_cast<int>(num) && !std::isnan(num) && !std::isinf(num) && num <= 1000000)
			PRINT CYN BOLD ".0" CLR;
		NEWL;
	}
	else
		PRINT CYN BOLD "impossible" CENDL;
}
