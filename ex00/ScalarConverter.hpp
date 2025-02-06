/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:49:38 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/06 13:28:35 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cstdlib>
# include <climits>
# include <cstring>
# include <cmath>
# include <cerrno>
# include <iomanip>
# include <iostream>
# include <spellBook.hpp>

enum _types
{
	NONE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
};

class ScalarConverter
{
	public:
		static void	convert(const std::string &param);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator =(const ScalarConverter &rhs);
		~ScalarConverter();
		
		template<typename T>
		static void	print(const T &param)
		{
			switch (type)
			char Char = static_cast<char>(param);
			int Int = static_cast<int>(param);
			float Float = static_cast<float>(param);
			double Double = static_cast<double>(param);
			if (std::isnan(Float) || std::isinf(Float))
				PRINT CYN BOLD "char: impossible" CENDL;
			else if (Char > 0 && Char < 127 && std::isprint(Char))
				PRINT CYN BOLD "char: '" AND Char AND "'" CENDL;
			else
				PRINT CYN BOLD "char: not printable" CENDL;
			if (std::isnan(Float) || std::isinf(Float))
				PRINT CYN BOLD "int: impossible" CENDL;
			else if ((long int)Float >= INT_MIN && (long int)Float <= INT_MAX)
				PRINT CYN BOLD "int: " AND Int CENDL;
			else
				PRINT CYN BOLD "int: impossible" CENDL;
			if ((Double < 0 && Double >= -__FLT_MAX__ && Double <= -__FLT_MIN__)
				|| (Double > 0 && Double <= __FLT_MAX__ && Double >= __FLT_MIN__)
				|| Double == 0 || std::isnan(Float) || std::isinf(Float))
				PRINT CYN BOLD "float: " AND Float AND "f" CENDL;
			else
				PRINT CYN BOLD "float: impossible" CENDL;
			PRINT CYN BOLD "double: " AND Double CENDL;
		}
};
